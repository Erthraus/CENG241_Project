#include "Scene.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void Scene::gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

/*void Scene::createMap()
{
	for (size_t i{ 0 }; i < LEN; i++)
	{
		map[0][i] = '-';
		map[LEN-1][i] = '-';
	}

	for (size_t i{ 1 }; i < WID; i++)
	{
		map[i][0] = '|';
		map[i][WID - 1] = '|';
	}
}*/

/*void Scene::drawMap()
{
	for (size_t i{ 0 }; i < LEN; i++)
	{
		for (size_t j{ 0 }; j < WID; j++)
		{
			if (map[i][j] == NULL)
				continue;
			cout << map[i][j];
		}
	}
}*/

void Scene::drawMap()
{
	for (size_t i{0}; i < WID; i++)
	{
		gotoxy(i, 0);
		cout << '-';
		gotoxy(i, LEN);
		cout << '-';
	}

	for (size_t i{1}; i < LEN; i++)
	{
		gotoxy(0, i);
		cout << '|';
		gotoxy(WID, i);
		cout << '|';
	}
}

void Scene::controller(short *x, short *y)
{
    if (_kbhit()) {
        switch (_getch()) {

        case 'w':
			(*y)--;
            break;

        case 's':
			(*y)++;
            break;

        case 'a':
			(*x)--;
            break;

        case 'd':
			(*x)++;
            break;

        default:
            break;
        }
    }
}

void Scene::setup()
{
	//createMap();
}

void Scene::update()
{
	controller(&x, &y);
}

void Scene::draw()
{
	drawMap();
	gotoxy(x, y);
	cout << character;
}
