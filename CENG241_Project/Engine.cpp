#include "Engine.h"
#include <windows.h>
#include <time.h>
#include <iostream>

void Engine::Run()
{
	srand(time(0));
	int choice;
	std::cout << "Choose your Character (0 - 4): ";
	std::cin >> choice;
	
	Scene scene{ choice };
	scene.setup();

	while (scene.gameison)
	{
		scene.update();
		scene.draw();
		Sleep(100);
		system("cls");
	}

	if (scene.win)
		std::cout << "VICTORY" << std::endl;

	else
		std::cout << "DEFEAT" << std::endl;

	system("pause");
}