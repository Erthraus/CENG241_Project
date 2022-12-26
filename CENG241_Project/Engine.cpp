#include "Engine.h"
#include <windows.h>
#include <time.h>

void Engine::Run()
{
	srand(time(0));
	scene.setup();

	while (scene.gameison)
	{
		scene.update();
		scene.draw();
		Sleep(100);
		system("cls");
	}
}