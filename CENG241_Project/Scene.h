#pragma once

#include <windows.h>
#include <string>
#include "Enemy.h"
#include <vector>
#include "Character.h"
#include "Player.h"

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
		void Controller();
		void drawCursor();
		void generateEnemies();
		void drawEnemy(Character& currentEnemy);
		void drawPlayer(Character& player);
		void selectEnemy();
		void drawHealthBar(int HP, int maxHP, int choice);

	public:
		int turn = 1;
		bool gameison = true;
		void setup();
		void update();
		void draw();
		int impcount, vampirecount, cyclopscount, demoncount, totalEnemies;
		vector<Imp> imps;
		vector<Vampire> vampires;
		vector<Cyclops> cyclopses;
		vector<Demon> demons;
		Character currentEnemy;
		string currentEnemyType;
		Player player{ 1 };
};

