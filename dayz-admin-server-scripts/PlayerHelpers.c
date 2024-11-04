enum Identity {
	ANY,
	NAME,
	STEAMID,
	PID
}

static class PlayerHelpers
{
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
}