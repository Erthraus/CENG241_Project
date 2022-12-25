#include "Scene.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

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

void Scene::changeFontSize(short height = 36, short width = 36)
{
	static CONSOLE_FONT_INFOEX  font;
	font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(output, 0, &font);
	font.FontWeight = 700;
	font.dwFontSize.X = height;
	font.dwFontSize.Y = width;
	SetCurrentConsoleFontEx(output, NULL, &font);
}

void Scene::drawMap()	//Function to draw Map
{
	changeFontSize();

	for (size_t i{1}; i < WID; i++)
	{
		gotoxy(i, 0);
		cout << '-';
		gotoxy(i, LEN - LEN/4);
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

void Scene::drawUI()
{
	changeFontSize(100);
	gotoxy(WID / 2 + WID / 5, 3 * LEN / 4 + 2);
	cout << "FIGHT";
}

void Scene::controller(short *x, short *y)	//Function to get user input and change gotoxy parameters 
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

void Scene::setup()		//Sets up the game
{
	setColor();
	changeFontSize(50, 50);
	cout << "deneme";
}

void Scene::update()	//For things which should be checked and updated constantly
{
	controller(&x, &y);
}

void Scene::draw()		//Draws frames
{
	drawMap();
	drawUI();
	gotoxy(x, y);
	cout << character;
}
