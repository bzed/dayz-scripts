enum Identity {
	ANY,
	NAME,
	STEAMID,
	PID
}

static class PlayerHelpers
{
	static bool KillPlayer(string tag)
	{
		PlayerBase player = GetPlayer(tag, Identity.ANY);
		
		if (!player)
		{
			return false;
		}
		
		player.SetHealth("", "", -1);
		
		return true;
	}
	
	void RestoreHealth(PlayerBase playerAsking, string tag)
	{
		PlayerBase player = GetPlayer(tag, Identity.ANY);
		if(!player)
		{
			ChatMessage.SendPlayerMessage(playerAsking, "target '" + name + "' not found.");
			return;
		}
		
		player.SetHealth("GlobalHealth", "Blood", player.GetMaxHealth("GlobalHealth", "Blood"));
		player.SetHealth("GlobalHealth", "Health", player.GetMaxHealth("GlobalHealth", "Health"));
		player.SetHealth("GlobalHealth", "Shock", player.GetMaxHealth("GlobalHealth", "Shock"));
	}
	

	static PlayerBase GetPlayer(string tag, Identity type)
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		
		PlayerBase p;
		
		bool nameMatch;
		bool steamIdMatch;
		bool pidMatch;
		
		for ( int i = 0; i < players.Count(); ++i )
		{
			Class.CastTo(p, players.Get(i));
			
			// Store matches from different checks
			nameMatch = p.GetIdentity().GetName() == tag;
			steamIdMatch = p.GetIdentity().GetPlainId() == tag;
			pidMatch = p.GetID() == tag.ToInt();
			
			if ( type == Identity.ANY ) 
			{
				if ( nameMatch || steamIdMatch || pidMatch )
				{
					return p;
				}
			}
			else if ( type == Identity.NAME )
			{
				if ( nameMatch )
				{
					return p;
				}
			}
			else if ( type == Identity.STEAMID )
			{
				if ( steamIdMatch )
				{
					return p;
				}
			}
			else if ( type == Identity.PID )
			{
				if ( pidMatch )
				{
					return p;
				}
			}
		}
		
		// Player with given parameter not found
		return NULL;
	}
	
	void SafeSetPos(PlayerBase player, string pos)
	{
		// Safe conversion
		vector p = pos.ToVector();
		
		// Check that position is a valid coordinate
		// 0 0 0 wont be accepted even though valid
		if (!p) 
		{
			ChatMessage.SendPlayerMessage(player, "Invalid coordinates.");
			return;
		}
		
		if(p[1] != 0)
		{
			player.SetPosition(p);
		}
		else
		{
			// Get safe surface value for Y coordinate in that position
			p[1] = GetGame().SurfaceY(p[0], p[2]);
			player.SetPosition(p);
		}
	}	
}