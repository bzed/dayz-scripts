#include "AdminCommands.c"

class JcAspesMission: MissionGameplay //MissionServer
{
	AdminCommands adminCommands;
	override void OnInit()
	{
		super.OnInit();
		adminCommands = new AdminCommands();
		//DeveloperFreeCamera.FreeCameraToggle( PlayerBase.Cast( GetGame().GetPlayer() ), false );
	}

	override void OnEvent(EventType eventTypeId, Param params)
	{
		switch(eventTypeId)
		{
			// Handle user command
			case ChatMessageEventTypeID:
				ChatMessageEventParams chatParams;
				Class.CastTo(chatParams, params);
				if(adminCommands.OnEvent(chatParams))
				{
					return;
				}
			break;
		}
		
		// Call super class event handler to handle other events
		super.OnEvent(eventTypeId, params);
	}
};
