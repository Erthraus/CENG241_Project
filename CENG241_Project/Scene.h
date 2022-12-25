#pragma once

#include <windows.h>
#include <string>

#define LEN 40
#define WID 150

class Scene
{
	private:
		int ch = 0;
		void drawMap();
		void drawArr(std::string arr[5], int size, COORD pos);
		void gotoxy(int x, int y);
		void setColor(short color);
		void drawUI();
		void updateCursor();
		void drawCursor();

	public:
		void setup();
		void update();
		void draw();
};

