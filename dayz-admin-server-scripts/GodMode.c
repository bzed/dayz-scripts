class GodMode
{
	// Players that have God Mode enabled, listed here
	private ref TIntArray m_gods;
	
	void GodMode()
	{
		m_gods = new TIntArray;
	}
	
	void ManagePlayer(PlayerBase player, bool activate)
	{
		if(activate)
		{
			// Add player to gods, call godmode function every 1 sec
			int pId = player.GetID();
			if ( m_gods.Find(pId) != -1 )
			{
				ChatMessage.SendPlayerMessage(player, "Player is already god.");
				return;
			}
			m_gods.Insert(pId);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SetGodMode, 1000, true, player);
			ChatMessage.SendPlayerMessage(player, "Godmode enabled.");
		}
		else
		{
			// Do vice versa except for other gods
			// Remove player id from gods list if found
			int godIdx = m_gods.Find( player.GetID() );
			if (godIdx == -1)
			{
				ChatMessage.SendPlayerMessage(player, "Player not found in gods.");
				return;
			}
			else
			{
				m_gods.Remove(godIdx);
			}
			
			// Remove godmode function from call queue but add again for remaining gods
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(this.SetGodMode);
			
			foreach (int pid : m_gods)
			{
				PlayerBase godPlayer = PlayerHelpers.GetPlayer(pid.ToString(), Identity.PID);
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.SetGodMode, 1000, true, godPlayer);
			}
			ChatMessage.SendPlayerMessage(player, "Godmode disabled.");
		}
	}

	void SetGodMode(PlayerBase player)
	{
		if (!player)
		{
			return;
		}
		
		if (player.GetHealth("", "") <= 0.0)
		{
			m_gods.Remove( player.GetID() );
			return;
		}
		
		// If player is not god, do nothing
		if (m_gods.Find( player.GetID() ) == -1)
		{
			return;
		}
		
		// Set all health statuses to maximum
		PlayerHelpers.RestoreHealth(player);
	}
}