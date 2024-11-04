static class ChatMessage
{
	static void SendPlayerMessage(PlayerBase player, string message)	
	{
		Param1<string> Msgparam;
		Msgparam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
	}
	
	static void ClearAllPlayersChat()
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		for ( int i = 0; i < players.Count(); ++i )
		{
			PlayerBase p;
			Class.CastTo(p, players.Get(i));
			for (int x = 0; x < 15; x++)
			{
				SendPlayerMessage(p, "");
			}
		}
	}

	static void SendGlobalMessage(string message)	
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers( players );
		
		for ( int i = 0; i < players.Count(); ++i )
		{
			Man player = players.Get(i);
			if ( player )
				SendPlayerMessage(PlayerBase.Cast(player), message);
		}
	}
	
	static void SendPlayerMessage(PlayerBase player, string message)	
	{
		Param1<string> Msgparam;
		Msgparam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, player.GetIdentity());
	}
}