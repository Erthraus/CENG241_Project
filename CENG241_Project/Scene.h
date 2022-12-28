#pragma once
#include <string>
#include <Windows.h>

class Scene
{
	public:
		static int characterChoice, replay;
		static bool gameison, winStatus;
		void drawArr(std::string arr[], int size, COORD pos);
		void gotoxy(int x, int y);
		void setColor(short color = 10);
};