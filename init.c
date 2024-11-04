#include "JcAspesScripts\GameInit.c"
#include "JcAspesScripts\JcAspesMission.c"

Mission CreateCustomMission(string path)
{
	return new JcAspesMission();
}

void main()
{
	GameInit gameInit = new GameInit();
	gameInit.CreatePlayer();
}
