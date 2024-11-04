#include "$CurrentDir:JcAspesScripts\\ChatMessages.c"
#include "$CurrentDir:JcAspesScripts\\PlayerHelpers.c"
#include "$CurrentDir:JcAspesScripts\\StringHelpers.c"
#include "$CurrentDir:JcAspesScripts\\Admin.c"
#include "$CurrentDir:JcAspesScripts\\CarSpawner.c"
#include "$CurrentDir:JcAspesScripts\\CursorAction.c"
#include "$CurrentDir:JcAspesScripts\\GearSpawner.c"
#include "$CurrentDir:JcAspesScripts\\GodMode.c"
#include "$CurrentDir:JcAspesScripts\\Teleporter.c"
#include "$CurrentDir:JcAspesScripts\\AdminCommands.c"
#include "$CurrentDir:JcAspesScripts\\GameInit.c"
#include "$CurrentDir:JcAspesScripts\\JcAspesMission.c"

Mission CreateCustomMission(string path)
{
	return new JcAspesMission();
}

void main()
{
	GameInit gameInit = new GameInit();
	gameInit.CreatePlayer();
}
