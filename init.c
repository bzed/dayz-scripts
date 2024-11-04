#include "$CurrentDir:dayz-admin-server-scripts\\ChatMessages.c"
#include "$CurrentDir:dayz-admin-server-scripts\\PlayerHelpers.c"
#include "$CurrentDir:dayz-admin-server-scripts\\StringHelpers.c"
#include "$CurrentDir:dayz-admin-server-scripts\\Admin.c"
#include "$CurrentDir:dayz-admin-server-scripts\\CarSpawner.c"
#include "$CurrentDir:dayz-admin-server-scripts\\CursorAction.c"
#include "$CurrentDir:dayz-admin-server-scripts\\GearSpawner.c"
#include "$CurrentDir:dayz-admin-server-scripts\\GodMode.c"
#include "$CurrentDir:dayz-admin-server-scripts\\Teleporter.c"
#include "$CurrentDir:dayz-admin-server-scripts\\AdminCommands.c"
#include "$CurrentDir:dayz-admin-server-scripts\\GameInit.c"
#include "$CurrentDir:dayz-admin-server-scripts\\MissionBase.c"

Mission CreateCustomMission(string path)
{
	return new DayzAdminServerScriptsMission();
}

void main()
{
	GameInit gameInit = new GameInit();
	gameInit.CreatePlayer();
}
