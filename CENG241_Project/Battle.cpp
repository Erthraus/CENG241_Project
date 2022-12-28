#include "Battle.h"
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

void Battle::drawMap()	//Function to draw Map
{
	if (turn % 2)
		setColor();
	else
		setColor(4);

	for (size_t i{ 1 }; i < WID; i++)
	{
		gotoxy(i, 0);
		cout << '-';
		gotoxy(i, LEN - LEN / 4 + 2);
		cout << '-';
		gotoxy(i, LEN);
		cout << '-';
	}

	for (size_t i{ 0 }; i < LEN + 1; i++)
	{
		gotoxy(0, i);
		cout << '|';
		gotoxy(WID, i);
		cout << '|';
	}
}

void Battle::drawUI()	//Function to draw User Interface
{
	gotoxy(1, 1);
	setColor(5);
	cout << " TURN: " << turn;
	gotoxy(1, 2);
	cout << " Remaining Enemies: " << totalEnemies;

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

	drawHealthBar(currentEnemy.getHP(), currentEnemy.getMaxHP(), 0);
	drawHealthBar(player.getHP(), player.getMaxHP(), 1);
}

void Battle::drawHealthBar(int HP, int maxHP, int choice)	// 0 for enemies, 1 for player
{
	float healthperbox = float(maxHP) / 10.0;
	
	if (choice)
	{
		COORD pos;
		pos.X = WID / 6;
		pos.Y = LEN / 6;
		setColor();

		gotoxy(pos.X, pos.Y);
		cout << HP;
		gotoxy(pos.X, pos.Y + 1);
		if (player.getHP())
		{
			for (size_t i = 0; i < float(HP) / healthperbox; i++)
			{
				if (i == 5)
					gotoxy(pos.X, pos.Y + 2);
				cout << "[]";
			}
		}
	}

	else
	{
		COORD enemy;
		enemy.X = WID * 3 / 4;
		enemy.Y = LEN * 3 / 4 - 3;
		setColor(4);

		gotoxy(enemy.X, enemy.Y);
		cout << HP;
		gotoxy(enemy.X, enemy.Y + 1);
		if (currentEnemy.getHP())
		{
			for (size_t i = 0; i < float(HP) / healthperbox; i++)
			{
				if (i == 5)
					gotoxy(enemy.X, enemy.Y + 2);
				cout << "[]";
			}
		}
	}
}

void Battle::Controller()		//Function to get user inputs
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

		case '\r':				// \r means enter
			if (turn % 2)
			{
				if (ch)
				{
					player.Defence();
					turn++;
				}

				else
				{
					player.Attack(currentEnemy);
					if (currentEnemy.getHP() == 0)
					{
						if (currentEnemyType == "imp")
						{
							totalEnemies--;
							impcount--;

						}
						else if (currentEnemyType == "vampire")
						{
							totalEnemies--;
							vampirecount--;
						}
						else if (currentEnemyType == "cyclops")
						{
							totalEnemies--;
							cyclopscount--;
						}
						else if (currentEnemyType == "demon")
						{
							totalEnemies--;
							demoncount--;
						}
						if (totalEnemies == 0)
						{
							winStatus = true;
							gameison = false;
							break;
						}

						selectEnemy();

					}
					turn++;
				}

				Sleep(100);
			}
			break;

		default:
			break;
		}
	}

	if (ch < 0)
		ch = 1;

	ch %= 2;
}

void Battle::drawCursor()		//Function to draw Player cursor
{
	setColor(6);
	int size{ 3 };
	COORD pos;
	string* arrow = new string[size];
	arrow[0] = " * ";
	arrow[1] = "***";
	arrow[2] = " * ";

	if (ch)
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

void Battle::generateEnemies()		//Function to generate a horde of enemies
{
	impcount = rand() % 5 + 1;
	vampirecount = rand() % 4 + 1;
	cyclopscount = rand() % 3 + 1;
	demoncount = rand() % 2 + 1;
	totalEnemies = impcount + vampirecount + cyclopscount + demoncount;

	Imp* imparr = new Imp[impcount];
	Vampire* vamparr = new Vampire[vampirecount];
	Cyclops* cycarr = new Cyclops[cyclopscount];
	Demon* demarr = new Demon[demoncount];

	for (size_t i = 0; i < impcount; i++)
	{
		imps.push_back(imparr[i]);
	}

	for (size_t i = 0; i < vampirecount; i++)
	{
		vampires.push_back(vamparr[i]);
	}

	for (size_t i = 0; i < cyclopscount; i++)
	{
		cyclopses.push_back(cycarr[i]);
	}

	for (size_t i = 0; i < demoncount; i++)
	{
		demons.push_back(demarr[i]);
	}

	delete[] imparr;
	delete[] vamparr;
	delete[] cycarr;
	delete[] demarr;
}

void Battle::drawEnemy(Character& currentEnemy)		//Function to draw Enemy art
{
	COORD pos;
	if (currentEnemyType == "cyclops")
		pos.Y = LEN / 10;
	else
		pos.Y = LEN / 4;
	pos.X = 3 * WID / 4;
	setColor(4);
	drawArr(currentEnemy.art, currentEnemy.artsize, pos);
}

void Battle::drawPlayer(Character& player)		//Function to draw Player art
{
	COORD pos;
	pos.X = WID / 10;
	pos.Y = 10;
	setColor(3);
	drawArr(player.art, player.artsize, pos);
}

void Battle::selectEnemy()		//Function to select the Current enemy
{
	int flag = 1;

	while (flag)
	{
		int selector = rand() % 4;

		if (selector == 0)
		{
			for (size_t i = 0; i < impcount; i++)
			{
				if (imps.at(i).getHP() > 0)
				{
					currentEnemy = imps.at(i);
					currentEnemyType = "imp";
					flag = 0;
				}
			}
		}

		else if (selector == 1)
		{
			for (size_t i = 0; i < vampirecount; i++)
			{
				if (vampires.at(i).getHP() > 0)
				{
					currentEnemy = vampires.at(i);
					currentEnemyType = "vampire";
					flag = 0;
				}
			}
		}

		else if (selector == 2)
		{
			for (size_t i = 0; i < cyclopscount; i++)
			{
				if (cyclopses.at(i).getHP() > 0)
				{
					currentEnemy = cyclopses.at(i);
					currentEnemyType = "cyclops";
					flag = 0;
				}
			}
		}

		else if (selector == 3)
		{
			for (size_t i = 0; i < demoncount; i++)
			{
				if (demons.at(i).getHP() > 0)
				{
					currentEnemy = demons.at(i);
					currentEnemyType = "demon";
					flag = 0;
				}
			}
		}
	}
}

void Battle::enemyAttack()		//Algorithm for enemy behavior
{
	if (turn % 2 == 0)
	{
		if (timer > 16)
		{
			timer = 0;

			if (currentEnemy.getMaxHP() / currentEnemy.getHP() >= 2)
			{
				if (rand() % 2)
					currentEnemy.Defence();
				else
					currentEnemy.Attack(player);

				turn++;
			}

			else
			{
				currentEnemy.Attack(player);
				turn++;
			}

			if (player.getHP() <= 0)
			{
				gameison = false;
				winStatus = false;
			}
		}

		timer++;
	}
}

void Battle::setup()		//Sets up the game
{
	gameison = true;
	winStatus = false;
	generateEnemies();
	selectEnemy();
}

void Battle::update()	//For things which should be checked and updated constantly
{
	Controller();
	enemyAttack();
}

void Battle::draw()		//Draws frames
{
	drawMap();
	drawUI();
	drawCursor();
	drawPlayer(player);
	drawEnemy(currentEnemy);
}