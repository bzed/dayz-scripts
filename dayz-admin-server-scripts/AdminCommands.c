#include "Admin.c"
#include "ChatMessages.c"
#include "PlayerHelpers.c"
#include "StringHelpers.c"
#include "GodMod.c"
#include "Cars.c"
#include "GearSpawer.c"

class AdminCommands
{
	const string helpMsg = "Available commands: /help /cursor /car /warp /kill /give /gear /ammo /say /info /heal /god /suicide /here /there";

	Admins admins;
	GodMode godMode;
	
	void AdminCommands()
	{
		admins = new Admins();
		godMode = new GodMode();
	}
	
	private bool ExtractCommand(ChatMessageEventParams chatParams, out string cmd)
	{
		// Remove those stupid ' ' => Substring: x, false, false, quotes = false
		// Check that input was a command (contains forward slash)
		cmd = string.ToString(chatParams.param3, false, false, false);
	
		// command format: /abc def ghi
		// if not command, is normal chat message
		if ( cmd.Get(0) != "/" )
		{
			return false;
		}
		
		return true;
	}
	
	private bool ExtractPlayer(ChatMessageEventParams chatParams, out PlayerBase sender)
	{
		// Get sender player name as string
		string senderName = string.ToString(chatParams.param2, false, false, false);
		
		// Get sender player object
		sender = PlayerHelpers.GetPlayer(senderName, Identity.NAME);
		
		// If fails to get the message sender, stop
		if (!sender)
		{
			return false;
		}
		
		return true;
	}
	
	bool OnEvent(ChatMessageEventParams chatParams)
	{
		string cmd;
		if(!ExtractCommand(chatParams, cmd))
		{
			return false;
		}
		
		// To avoid players to see commands
		ChatMessage.ClearAllPlayersChat();
	
		// Get player how sent command
		PlayerBase senderPlayer;
		if(!ExtractPlayer(chatParams, senderPlayer))
		{
			return false;
		}
		
		// Check that player has sufficient privileges to execute commands
		if ( !admins.IsAdmin(senderPlayer) )
		{
			ChatMessage.SendPlayerMessage(senderPlayer, "Sorry, you are not an admin!");
			return false;
		}
		
		// Execute specified command
		Command(senderPlayer, cmd);
		
		// Return after execution instead of breaking to prevent normal event handling
		return true;
	}

	private void Command(PlayerBase player, string command)
	{
		// Split command message into args
		TStringArray args = new TStringArray;
		StringHelpers.Split(command, " ", args);
		
		string arg;
		PlayerBase target;
		int dist;
		switch (args[0])
		{
			case "/god":
				ExecuteGodMode(player, args);
				break;
			case "/cursor":
				ExecuteCursorAction(player, args);
				break;
			case "/kill":
				ExecuteKill(player, args);
				break;
			case "/suicide":
				ExecuteSuicide(player, args);
				break;
			case "/car":
				ExecuteCar(player, args);
				break;
			case "/warp":
				ExecuteWarp(player, args);
				break;
			case "/heal":
				ExecuteHeal(player, args);
				break;
			case "/gear":
				ExecuteGear(player, args);
				break;
			case "/ammo":
				ExecuteAmmo(player, args);
				break;
			case "/info":
				ExecuteInfo(player, args);
				break;
			case "/say":
				ExecuteSay(player, args, command);
				break;
			case "/give":
				ExecuteGive(player, args);
				break;
			case "/here":
				ExecuteHere(player, args, command);
				break;
			case "/there":
				ExecuteThere(player, args, command);
				break;
			default:
				ChatMessage.SendPlayerMessage(player, "Unknown command!");
			case "/help":
				ChatMessage.SendPlayerMessage(player, helpMsg);
		}
	}
	
	//DeveloperFreeCamera.FreeCameraToggle( PlayerBase.Cast( GetGame().GetPlayer() ), false );

	private void ExecuteSuicide(PlayerBase player, TStringArray args)
	{
		if ( args.Count() != 1 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /suicide - Commit a suicide");
			return;
		}
		
		// Use SteamID here for sake of certainty
		if (!PlayerHelpers.KillPlayer( player.GetIdentity().GetPlainId() ))
		{
			ChatMessage.SendPlayerMessage(player, "Could not commit suicide.");
		}
	}
	
	private bool PrepareTeleport(TStringArray args, string command, out int distance, out PlayerBase target)
	{
		// Parse target player name: "...stuff 'input' stuff..." -> "input"
		string name = StringHelpers.Trim(command, "'");
		int distance = args[args.Count() - 1].ToInt();
		PlayerBase target = PlayerHelpers.GetPlayer(name, Identity.ANY);
		
		if (!target)
		{
			SendPlayerMessage(player, "Could not find target player.");
			return false;
		}
		
		if (dist < 1)
		{
			SendPlayerMessage(player, "Invalid distance.");
			return false;
		}
		
		return true;
	}
	
	private void ExecuteThere(PlayerBase player, TStringArray args, string command)
	{
		if ( args.Count() < 2 )
		{
			SendPlayerMessage(player, "Syntax: /there '[PLAYER IDENTITY]' (DISTANCE) - Moves self to a player");
			return false;
		}
		
		string name;
		int distance;
		if(PrepareTeleport(player, args, command, distance, target))
		{
			TeleportPlayer(player, target, dist);					
		}
	}
	
	private void ExecuteHere(PlayerBase player, TStringArray args, string command)
	{
		if ( args.Count() < 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /here '[PLAYER IDENTITY]' (DISTANCE) - Moves a player to self");
			return;
		}
		
		string name;
		int distance;
		if(PrepareTeleport(player, args, command, distance, target))
		{
			TeleportPlayer(target, player, dist);							}
		}
	}
	
	private void ExecuteGive(PlayerBase player, TStringArray args)
	{
		if ( args.Count() < 2 || args.Count() > 4 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /give [ITEM_NAME] (AMOUNT) (distance) - Spawn item on ground, default amount is 1, default distance is 0");
			return;
		}
		
		// Set spawn pos near player
		vector spawnPosition = player.GetPosition();
		if(args.Count() == 4)
		{
			float distance = args[4].ToFloat();
			spawnPosition[0] = spawnPosition[0] + distance;
			spawnPosition[1] = GetGame().SurfaceY(spawnPosition[0], spawnPosition[2]);
			spawnPosition[2] = spawnPosition[2] + distance;
		}
		
		EntityAI item = player.SpawnEntityOnGroundPos(args[1], spawnPosition);
		
		if (!item)
		{
			ChatMessage.SendPlayerMessage(player, "ERROR: Could not create item.");
			return;
		}
		
		if ( args.Count() == 3 || args.Count() == 4 )
		{
			
			int itemCount = args[2].ToInt();
			if (itemCount <= 0)
			{
				ChatMessage.SendPlayerMessage(player, "ERROR: Invalid count.");
				return;
			}
			
			// Spawn the rest of the items if count was specified and valid
			for (int i = 0; i < itemCount - 1; i++)
			{
				player.SpawnEntityOnGroundPos(args[1], spawnPosition);
			}
		}
		ChatMessage.SendPlayerMessage(player, "Item(s) spawned.");
	}
	
	private void ExecuteSay(PlayerBase player, TStringArray args, string command)
	{
		if ( args.Count() < 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /say [MESSAGE] - Global announcement to all players");
			return;
		}
		
		// Form the message string from the command text and send to all players
		string msg = command.Substring( 5, command.Length() - 5 );
		
		ChatMessage.SendGlobalMessage(msg);
	}
	
	private void ExecuteInfo(PlayerBase player, TStringArray args)
	{
		if ( args.Count() < 1 || args.Count() > 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /info (0/1) - Get information about players on the server or set continuous info on/off");
			return;
		}
		
		if (args.Count() == 2)
		{
			arg = args[1];
			arg.ToLower();
			if (arg.ToInt() == 1)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(PlayerHelpers.PlayerInfo, 20000, true, player);
				ChatMessage.SendPlayerMessage(player, "Continuous info mode enabled.");
			}
			else if (arg.ToInt() == 0)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(PlayerHelpers.PlayerInfo);
				ChatMessage.SendPlayerMessage(player, "Continuous info mode disabled.");
			}
		}
		else
		{
			PlayerHelpers.PlayerInfo(player);
		}
	}
		
	private void ExecuteAmmo(PlayerBase player, TStringArray args)
	{
		// Args count: 2 <= x <= 3
		if ( args.Count() < 2 || args.Count() > 3 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /ammo [FOR_WEAPON] (AMOUNT) - Spawn mags and ammo for weapon");
			GearSpawner.SpawnAmmo(player, "help");
			return;
		}
		
		if ( args.Count() == 3 && GearSpawner.SpawnAmmo(player, args[1], args[2].ToInt()) )
		{
			ChatMessage.SendPlayerMessage(player, "Ammo spawned.");
		}
		else if ( args.Count() == 2 && GearSpawner.SpawnAmmo(player, args[1]) )
		{
			ChatMessage.SendPlayerMessage(player, "Ammo spawned.");
		}
	}

	private void ExecuteGear(PlayerBase player, TStringArray args)
	{
		if ( args.Count() != 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /gear [TYPE] - Spawn item loadout to self");
			GearSpawner.SpawnGear(player, "help");
		}
		else if (GearSpawner.SpawnGear(player, args[1]))
		{
			ChatMessage.SendPlayerMessage(player, "Gear spawned.");
		}
	}
		
	private void ExecuteHeal(PlayerBase player, TStringArray args)
	{
		if ( args.Count() != 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /heal '[PLAYER IDENTITY]' - Set all health statuses to max");
			return;
		}
		
		string name = StringHelpers.Trim(args[1], "'");
		PlayerHelpers.RestoreHealth(player, name);

	}
	
	private void ExecuteWarp(PlayerBase player, TStringArray args)
	{
		if ( args.Count() < 3 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /warp [X] [Z] ([Y])- Teleport to [X, 0, Z] or [X, Y, Z]");
			return;
		}
		
		string pos = args[1] + " " + "0" + " " + args[2];
		if(args.Count() == 4)
		{
			pos = args[1] + " " + args[3] + " " + args[2];
		}
		
		PlayerHelpers.SafeSetPos(player, pos);
		ChatMessage.SendPlayerMessage(player, "Teleported to: " + pos);
	}
	
	private void ExecuteCar(PlayerBase player, TStringArray args)
	{
		if ( args.Count() != 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /car [TYPE] - Spawn a vehicle");
			Car.Spawn(player, "help");
			return;
		}
		Cars.SpawnCar(player, args[1]);
	}
	
	private void ExecuteKill(PlayerBase player, TStringArray args)
	{
		if ( args.Count() < 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /kill '[PLAYER IDENTITY]' - Kills a player by given identity, use single quotes around");
		}
		
		arg = StringHelper.Trim(args[1], "'");
		
		if (!PlayerHelpers.KillPlayer(arg))
		{
			ChatMessage.SendPlayerMessage(player, "Error: Could not kill player.");
		}	
	}

	private void ExecuteCursorAction(PlayerBase player, TStringArray args)
	{
		if ( args.Count() == 1 )
		{
			// Default action is shoing element near cursor
			CursorAction.Do(player, "show");
		}
		else
		{
			CursorAction.Do(player, args[1]);
		}
	}

	private void ExecuteGodMode(PlayerBase player, TStringArray args)
	{
		if ( args.Count() != 2 )
		{
			ChatMessage.SendPlayerMessage(player, "Syntax: /god [0-1] - Enable or disable semi-god mode");
			return;
		}
		
		int setGod = args[1].ToInt();
		if ( (setGod == 1) || (setGod == 0))
		{
			godMode.ManagePlayer(player, setGod == 1);
		}
		else
		{
			ChatMessage.SendPlayerMessage(player, "ERROR: Invalid argument given. Argument: 0-1");
		}
	}

}