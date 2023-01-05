#include "Scene.h"
#include <windows.h>
#include <string>
#include <iostream>

void Scene::gotoxy(int x, int y)			//Function to move cursor
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(output, pos);
}

void Scene::setColor(short color)		//Function to change the color of the cursor
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Cursor;
	GetConsoleCursorInfo(output, &Cursor);
	Cursor.bVisible = false;
	SetConsoleCursorInfo(output, &Cursor);
	SetConsoleTextAttribute(output, color);
}

void Scene::drawArr(std::string arr[], int size, COORD pos)		//Function to draw a string array to screen
{
	for (int i{ 0 }; i < size; i++)
	{
		gotoxy(pos.X, pos.Y++);
		std::cout << arr[i];
	}
}

void Scene::write(std::string str, COORD pos)		//Function to write strings letter by letter
{
	for (int i = 0; i < str.size(); i++)
	{
		gotoxy(pos.X, pos.Y);
		std::cout << str[i];
		Sleep(20);
		pos.X++;
	}

	Sleep(300);
}

int Scene::characterChoice = 0;
int Scene::replay = 1;
bool Scene::gameison = true;
bool Scene::winStatus = false;