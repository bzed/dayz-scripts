class CursorAction
{
	static void Do(PlayerBase player, string action)
	{
		// get pointed 1rst object
		Object obj = COM_GetCursorObject(player);
		if(obj)
		{
			action.ToLower();		
			switch(action)
			{
				case "show":
					ChatMessage.SendPlayerMessage(player, "First object under cursor:'" + obj.GetType() + "'|dispName:'" + obj.GetDisplayName() + "'|model:'" + obj.GetModelName() + "'");
					break;

				case "delete":
					obj.SetPosition(vector.Zero); // If object does not physically delete, teleport it to 0 0 0
					GetGame().ObjectDelete( obj );
					ChatMessage.SendPlayerMessage(player, "First object under cursor DELETED'" + obj.GetType() + "'|dispName:'" + obj.GetDisplayName() + "'|model:'" + obj.GetModelName() + "'");
					break;
				
				default:
					ChatMessage.SendPlayerMessage(player, "Syntax: /cursor display object name on cursor - [delete] => delete object on cursor");
					return;
			}
		}
		else
		{
			ChatMessage.SendPlayerMessage(player, "nothing found under cursor");
			return;

		}
	}
	
	static private set< Object > COM_GetObjectsAt( vector from, vector to, PlayerBase ignore = NULL, float radius = 0.5, Object with = NULL )
	{
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		int contact_component_view;
		
		set< Object > geom = new set< Object >;
		set< Object > view = new set< Object >;
		
		Debug.DrawLine(from, to, COLOR_BLUE);

		bool geomFound = DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, geom, with, ignore, false, false, ObjIntersectGeom, radius );
		bool viewFound = DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component_view, view, with, ignore, false, false, ObjIntersectView, radius );
		
		ChatMessage.SendPlayerMessage(ignore, "{" + geom.Count() + "} geom object found under cursor");
		ChatMessage.SendPlayerMessage(ignore, "{" + view.Count() + "} view object found under cursor");

		if ( viewFound && view.Count() > 0 ) 
		{
			for(int j = 0; j < view.Count(); j++)
			{
				Object currentObject2 = view[j];
				ChatMessage.SendPlayerMessage(ignore, "View under cursor: type:'" + currentObject2.GetType() + "' dispName:'" + currentObject2.GetDisplayName() + "' ID:'" + currentObject2.GetID());
			}
		}

		if ( geomFound && geom.Count() > 0 ) 
		{
			for(int i = 0; i < geom.Count(); i++)
			{
				Object currentObject = geom[i];
				ChatMessage.SendPlayerMessage(ignore, "Geom under cursor: type:'" + currentObject.GetType() + "' dispName:'" + currentObject.GetDisplayName() + "' ID:'" + currentObject.GetID());
			}
		}

		if ( viewFound && view.Count() > 0 ) 
		{
			return view;
		}
		
		if ( geomFound && geom.Count() > 0 ) 
		{
			return geom;
		}

		return NULL;
	}
	
	static private Object COM_GetCursorObject(PlayerBase player)
	{
		if(player)
		{
			vector rayStart = player.GetPosition();
			vector rayEnd = rayStart + (player.GetDirection() * 1000);
			
			set< Object > objs = COM_GetObjectsAt( rayStart, rayEnd, player, 0.5);
			
			if( objs && objs.Count() > 0 )
			{
				// log found objects
				/*SendPlayerMessage(player, "{" + objs.Count() + "} object found under cursor");
				for(int i = 0; i < objs.Count(); i++)
				{
					Object currentObject = objs[i];
					SendPlayerMessage(player, "Object under cursor: type:'" + currentObject.GetType() + "' dispName:'" + currentObject.GetDisplayName() + "' model:'" + currentObject.GetModelName() + "' " + currentObject.GetLocalPos(rayStart).ToString(true));
				}*/

				return objs[ 0 ];
			}
		}
		return NULL;
	}
}