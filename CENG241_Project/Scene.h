#pragma once

#define LEN 30
#define WID 100

class Scene
{
	private:
		short x = 5, y = 5;
		//char map[LEN][WID];
		char character = '*';
		//void createMap();
		void drawMap();
		void gotoxy(int x, int y);
		void controller(short *x, short *y);

	public:
		void setup();
		void update();
		void draw();
};

