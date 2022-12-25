#pragma once

#include <windows.h>

#define LEN 40
#define WID 150

class Scene
{
	private:
		short x = 5, y = 5;
		char character = '*';
		void drawMap();
		void gotoxy(int x, int y);
		void setColor(short color);
		void controller(short *x, short *y);
		void drawUI();
		void changeFontSize(short height, short width);

	public:
		void setup();
		void update();
		void draw();
};

