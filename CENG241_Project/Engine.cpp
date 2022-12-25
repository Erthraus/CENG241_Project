#include "Engine.h"
#include <windows.h>

void Engine::Run()
{
	scene.setup();

	while (1)
	{
		scene.update();
		scene.draw();
		Sleep(100);
		system("cls");
	}
}