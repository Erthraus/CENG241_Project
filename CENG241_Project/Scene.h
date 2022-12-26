#pragma once

#include <windows.h>
#include <string>
#include "Enemy.h"
#include <vector>
#include "Character.h"

#define LEN 40
#define WID 150

class Scene
{
	private:
		int ch = 0;
		void drawMap();
		void drawArr(string arr[], int size, COORD pos);
		void gotoxy(int x, int y);
		void setColor(short color);
		void drawUI();
		void updateCursor();
		void drawCursor();
		void generateEnemies();
		void drawEnemy(Character& currentEnemy);
		void selectEnemy();

	public:
		void setup();
		void update();
		void draw();
		int mushroomnum;
		vector<Mushroom> mushrooms;
		Character currentEnemy;
		Mushroom deneme;
};

