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
			battle->gotoxy(0, 0);
			battle->update();
			battle->draw();
		}

		delete battle;
		menu.End();
	} while (menu.replay);

	system("pause");
}