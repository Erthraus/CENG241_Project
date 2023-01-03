#pragma once

#include "Scene.h"
#include <string>
#include "Enemy.h"
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Menu.h"

#define LEN 40
#define WID 150

class Battle : public Scene
{
	private:
		int ch = 0, timer = 0;
		void drawMap();
		void drawUI();
		void Controller();
		void drawCursor();
		void generateEnemies();
		void drawEnemy(Character& currentEnemy);
		void drawPlayer(Character& player);
		void selectEnemy();
		void drawHealthBar(int HP, int maxHP, int choice);
		void enemyAttack();
		void pauseMenu();
		void updateCtr();

		string* attack{ nullptr };
		string* defence{ nullptr };
		string* buff{ nullptr };
		string* debuff{ nullptr };
		string* arrow{ nullptr };

	public:
		Battle() = default;
		
		~Battle()
		{
			delete[] attack;
			delete[] defence;
			delete[] buff;
			delete[] debuff;
			delete[] arrow;
		}
		
		int turn = 1, previousturn = 0;
		void setup();
		void update();
		void draw();
		int totalEnemies;
		int currentEnemyLoc;
		vector<Imp> imps;
		vector<Vampire> vampires;
		vector<Cyclops> cyclopses;
		vector<Demon> demons;
		Character currentEnemy;
		string currentEnemyType;
		Player player{ characterChoice };

		friend class Menu;
};