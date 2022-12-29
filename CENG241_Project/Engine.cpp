#include "Engine.h"
#include <windows.h>
#include <time.h>
#include "Battle.h"

void Engine::Run()
{
	srand(time(0));
	
	do {
		menu.Start();

		Battle* battle = new Battle;

		battle->setup();

		while (battle->gameison)
		{
			battle->update();
			battle->draw();
			Sleep(75);
			system("cls");
		}

		delete battle;
		menu.End();
	} while (menu.replay);

	system("pause");
}