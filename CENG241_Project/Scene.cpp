#include "Scene.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <vector>
#include "Character.h"
#include "Enemy.h"

using namespace std;

void Scene::gotoxy(int x, int y)	//Function to move cursor
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(output, pos);
}

void Scene::setColor(short color = 10)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Cursor;
	GetConsoleCursorInfo(output, &Cursor);
	Cursor.bVisible = false;
	SetConsoleCursorInfo(output, &Cursor);
	SetConsoleTextAttribute(output, color);
}

void Scene::drawMap()	//Function to draw Map
{
	setColor();

	for (size_t i{1}; i < WID; i++)
	{
		gotoxy(i, 0);
		cout << '-';
		gotoxy(i, LEN - LEN/4 + 2);
		cout << '-';
		gotoxy(i, LEN);
		cout << '-';
	}

	for (size_t i{0}; i < LEN + 1; i++)
	{
		gotoxy(0, i);
		cout << '|';
		gotoxy(WID, i);
		cout << '|';
	}
}

void Scene::drawArr(string arr[], int size, COORD pos)
{
	for (int i{ 0 }; i < size; i++)
	{
		gotoxy(pos.X, pos.Y++);
		cout << arr[i];
	}
}

void Scene::drawUI()
{
	COORD pos;
	int size{ 5 };
	pos.X = WID * 3 / 5;
	pos.Y = 3 * LEN / 4 + 4;
	string* attack = new string[size];
	string* defence = new string[size];
	//string* buff = new string[size];
	//string* debuff = new string[size];

	attack[0] = "    ^   -------  |   /  ";
	attack[1] = "   / \\     |     |  /  ";
	attack[2] = "  /---\\    |     |<    ";
	attack[3] = " /     \\   |     |  \\ ";
	attack[4] = "/       \\  |     |   \\";
	
	defence[0] = "|\\    -----  ----";
	defence[1] = "| \\   |      |   ";
	defence[2] = "|  |  |---   |--  ";
	defence[3] = "| /   |      |    ";
	defence[4] = "|/    -----  |    ";

	setColor(4);
	drawArr(attack, size, pos);

	pos.X = WID * 5 / 6;
	setColor(3);
	drawArr(defence, size, pos);
}

void Scene::updateCursor()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			ch--;
			break;

		case 'd':
			ch++;
			break;

		default:
			break;
		}
	}

	if (ch < 0)
		ch = 1;

	ch %= 2;
}

void Scene::drawCursor()
{
	setColor(6);
	int size{ 3 };
	COORD pos;
	string* arrow = new string[size];
	arrow[0] = " * ";
	arrow[1] = "***";
	arrow[2] = " * ";

	if(ch)
		pos.X = WID * 5 / 6 - 5;
	else
		pos.X = WID * 3 / 5 - 3;

	pos.Y = 3 * LEN / 4 + 5;

	switch (ch)
	{
		case 0:
			drawArr(arrow, size, pos);
			break;

		case 1:
			drawArr(arrow, size, pos);
			break;

		default:
			break;
	}
}

void Scene::generateEnemies()
{
	mushroomnum = rand() % 4;
	Mushroom* marr = new Mushroom[mushroomnum];

	for (size_t i = 0; i < mushroomnum; i++)
	{
		mushrooms.push_back(marr[i]);
	}

	delete[] marr;
}

void Scene::drawEnemy(Character& currentEnemy)
{
	COORD pos;
	pos.X = 4 * WID / 5;
	pos.Y = 2;
	drawArr(currentEnemy.art, currentEnemy.artsize, pos);
}

void Scene::selectEnemy()
{
	for (size_t i = 0; i < mushroomnum; i++)
	{
		if (mushrooms.at(i).getHP() < 0)
			continue;

		currentEnemy = mushrooms.at(i);
	}
}


void Scene::setup()		//Sets up the game
{	
	setColor();
	generateEnemies();
	selectEnemy();
}

void Scene::update()	//For things which should be checked and updated constantly
{
	updateCursor();
}

void Scene::draw()		//Draws frames
{
	drawMap();
	drawUI();
	drawCursor();
	drawEnemy(currentEnemy);
}
