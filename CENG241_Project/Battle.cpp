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
	setColor(7);
	cout << " TURN: " << turn;
	gotoxy(1, 2);
	cout << " Remaining Enemies: " << totalEnemies;

	COORD pos;
	pos.Y = 3 * LEN / 4 + 4;

	pos.X = WID * 5 / 8;
	setColor(12);
	drawArr(attack, 5, pos);

	pos.X = WID * 7 / 8;
	setColor(11);
	drawArr(defence, 5, pos);

	pos.X = WID / 8;
	setColor(14);
	drawArr(buff, 5, pos);

	pos.X = WID * 3 / 8;
	setColor(13);
	drawArr(debuff, 5, pos);

	drawHealthBar(currentEnemy->getHP(), currentEnemy->getMaxHP(), 0);
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
		for (size_t i = 0; i < float(HP) / healthperbox; i++)
		{
			if (i == 5)
				gotoxy(pos.X, pos.Y + 2);
			cout << "[]";
		}

		int posy = pos.Y + 1;
		if (player.isBuffed)
		{
			gotoxy(pos.X + 11, posy++);
			setColor(3);
			cout << "Buffed(+" << player.getattackCoef() - player.getOriginalAttackCoef()  << " AtkCoef)";
		}

		if (player.isburning)
		{
			gotoxy(pos.X + 11, posy++);
			setColor(4);
			cout << "Burning(-10HP)";
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
		for (size_t i = 0; i < float(HP) / healthperbox; i++)
		{
			if (i == 5)
				gotoxy(enemy.X, enemy.Y + 2);
			cout << "[]";
		}

		if (currentEnemy->isDebuffed)
		{
			gotoxy(enemy.X + 11, enemy.Y + 1);
			setColor(5);
			cout << "Debuffed(-" << currentEnemy->getOriginalAttackCoef() - currentEnemy->getattackCoef() << " AtkCoef)";
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
			system("cls");
			break;

		case 'd':
			ch++;
			system("cls");
			break;

		case '\r':				// \r means enter
			if (turn % 2)
			{
				playerHealth0 = player.getHP();
				enemyHealth0 = currentEnemy->getHP();

				if (ch == 3)
				{
					player.Defence();
					turn++;
					playerHealth1 = player.getHP();
					enemyHealth1 = currentEnemy->getHP();
				}

				else if (ch == 2)
				{
					player.Attack(*currentEnemy);
					playerHealth1 = player.getHP();
					enemyHealth1 = currentEnemy->getHP();
					if (currentEnemy->getHP() <= 0)
					{
						if (currentEnemyType == "imp")
						{
							totalEnemies--;
							imps.erase(imps.begin() + currentEnemyLoc);
						}
						else if (currentEnemyType == "vampire")
						{
							totalEnemies--;
							vampires.erase(vampires.begin() + currentEnemyLoc);
						}
						else if (currentEnemyType == "cyclops")
						{
							totalEnemies--;
							cyclopses.erase(cyclopses.begin() + currentEnemyLoc);
						}
						else if (currentEnemyType == "demon")
						{
							totalEnemies--;
							demons.erase(demons.begin() + currentEnemyLoc);
						}
						if (totalEnemies == 0)
						{
							winStatus = true;
							gameison = false;
							return;
						}

						selectEnemy();

					}
					
					turn++;
				}

				else if (ch == 1)
				{
					player.Debuff(*currentEnemy);
					currentEnemy->isDebuffed = true;
					currentEnemy->debuffCtr = 5;
					turn++;
				}

				else
				{
					player.Buff();
					player.isBuffed = true;
					player.buffCtr = 5;
					turn++;
				}

				system("cls");
				Sleep(100);
			}
			break;
		
		case 27:			//ESC key
			pauseMenu();
			break;

		default:
			break;
		}
	}

	if (ch < 0)
		ch = 3;

	ch %= 4;
}

void Battle::drawCursor()		//Function to draw Player cursor
{
	setColor(6);
	COORD pos;

	if (ch == 3)
		pos.X = WID * 7 / 8 - 4;
	else if (ch == 2)
		pos.X = WID * 5 / 8 - 3;
	else if (ch == 1)
		pos.X = WID * 3 / 8 - 4;
	else
		pos.X = WID / 8 - 4;

	pos.Y = 3 * LEN / 4 + 5;

	drawArr(arrow, 3, pos);
}

void Battle::generateEnemies()		//Function to generate a horde of enemies
{
	int impcount, vampirecount, cyclopscount, demoncount;

	impcount = rand() % 3 + 1;
	vampirecount = rand() % 2 + 1;
	cyclopscount = rand() % 2 + 1;
	demoncount = rand() % 1 + 1;
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
		pos.Y = LEN / 6;
	else
		pos.Y = LEN / 4;
	pos.X = 3 * WID / 4;

	if (currentEnemy.isDebuffed)
		setColor(5);
	else
		setColor(4);
	
	drawArr(currentEnemy.art, currentEnemy.artsize, pos);
}

void Battle::drawPlayer(Player& player)		//Function to draw Player art
{
	COORD pos;
	pos.X = WID / 10;
	pos.Y = 10;

	if (player.isburning)
		setColor(12);

	else if (player.isBuffed)
		setColor(6);

	else
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
			for (size_t i = 0; i < imps.size(); i++)
			{
					currentEnemy = &imps.at(i);
					currentEnemyType = "imp";
					currentEnemyLoc = i;
					flag = 0;
			}
		}

		else if (selector == 1)
		{
			for (size_t i = 0; i < vampires.size(); i++)
			{
					currentEnemy = &vampires.at(i);
					currentEnemyType = "vampire";
					currentEnemyLoc = i;
					flag = 0;
			}
		}

		else if (selector == 2)
		{
			for (size_t i = 0; i < cyclopses.size(); i++)
			{
					currentEnemy = &cyclopses.at(i);
					currentEnemyType = "cyclops";
					currentEnemyLoc = i;
					flag = 0;
			}
		}

		else if (selector == 3)
		{
			for (size_t i = 0; i < demons.size(); i++)
			{
					currentEnemy = &demons.at(i);
					currentEnemyType = "demon";
					currentEnemyLoc = i;
					flag = 0;
			}
		}
	}
}

void Battle::dialogue(int x)		//Function to output dialogue. 2 = attack, 1 = attacked, 0 = defence
{
	COORD pos;
	pos.X = 7 * WID / 10;
	pos.Y = LEN / 10;
	string text = currentEnemy->Quote(x);
	
	write(text, pos);
}

void Battle::enemyAttack()		//Enemy behavior
{
	if (turn % 2 == 0)
	{
		if (timer > 30)
		{
			timer = 0;
			int x = rand() % 11;
			playerHealth0 = player.getHP();
			enemyHealth0 = currentEnemy->getHP();

			if (currentEnemy->getMaxHP() * 6 / 10 >= currentEnemy->getHP())
			{
				if (x > 5) 
				{
				currentEnemy->Defence();
				dialogue(0);
				}

				else if(x > 2)
				{
				currentEnemy->Attack(player);
				dialogue(2);
				}

				else
				{
					currentEnemy->specialAbility(player);
					dialogue(3);
				}

				turn++;
			}

			else
			{
				if (x > 8)
				{
					if (currentEnemyType == "cyclops")
					{
						if (currentEnemy->getHP() != currentEnemy->getMaxHP())
						{
							currentEnemy->specialAbility(player);
							dialogue(3);
						}

						else
						{
							currentEnemy->Attack(player);
							dialogue(2);
						}
					}

					else
					{
						currentEnemy->specialAbility(player);
						dialogue(3);
					}
				}
				
				else
				{
					currentEnemy->Attack(player);
					dialogue(2);
				}

				turn++;
			}

			if (player.getHP() <= 0)
			{
				gameison = false;
				winStatus = false;
			}

			playerHealth1 = player.getHP();
			enemyHealth1 = currentEnemy->getHP();
			system("cls");
		}

		timer++;
	}
}

void Battle::pauseMenu()
{
	system("cls");
	COORD pos;
	pos.X = WID / 3;
	pos.Y = LEN / 4;

	string* pause = new string[10];
	pause[0] = "?????????        ??            ???           ???    ??????????????    ?????????????";
	pause[1] = "??      ??      ????           ???           ???    ??????????????    ?????????????";
	pause[2] = "??       ??    ??  ??          ???           ???    ??                ??           ";
	pause[3] = "??      ??    ??    ??         ???           ???    ??                ??           ";
	pause[4] = "??    ??     ??      ??        ???           ???    ??????????????    ?????????????";
	pause[5] = "??????      ????????????       ???           ???    ??????????????    ?????????????";
	pause[6] = "??         ??????????????      ???           ???                ??    ??           ";
	pause[7] = "??        ??            ??     ???           ???                ??    ??           ";
	pause[8] = "??       ??              ??    ?????????????????    ??????????????    ?????????????";
	pause[9] = "??      ??                ??   ?????????????????    ??????????????    ?????????????";

	setColor(11);
	drawArr(pause, 10, pos);

	string names[4]{ "Mustafa Kemal OZ", "Tuna YAVUZ", "Ege ALTUG", "Arda Celal KAPLAN" };
	
	pos.Y = LEN / 4 + 12;
	gotoxy(pos.X, pos.Y);
	cout << "CREDITS:";

	for (size_t i = 0; i < 4; i++)
	{
		setColor(i + 2);
		gotoxy(pos.X, ++pos.Y);
		cout << names[i];
	}

	cout << endl;
	system("pause");
	system("cls");
}

void Battle::updateCtr()
{
	if (previousturn < turn)
	{
		if (player.isBuffed)
		{
			if (player.buffCtr > 0)
			{
				player.buffCtr--;
			}

			else
			{
				player.setattackCoef(player.getOriginalAttackCoef());
				player.isBuffed = false;
			}
		}

		if (currentEnemy->isDebuffed)
		{
			if (currentEnemy->debuffCtr > 0)
			{ 
				currentEnemy->debuffCtr--;
			}

			else
			{
				currentEnemy->setattackCoef(currentEnemy->getattackCoef());
				currentEnemy->isDebuffed = false;
			}
		}

		if (player.isburning)
		{
			player.Burn();
		}

		announce();
		system("cls");
		previousturn = turn;
	}
}

void Battle::announce()
{
	COORD pos;
	pos.X = 3 * WID / 7;
	pos.Y = 3 * LEN / 4;

	string announcement;
	int pdamage = playerHealth0 - playerHealth1;
	int edamage = enemyHealth0 - enemyHealth1;

	if(edamage > 0)
	{
		if(enemyHealth0 != edamage) dialogue(1);
		Sleep(100);
		setColor(15);
		announcement = "You dealt " + to_string(edamage) + " damage to enemy";
		write(announcement, pos);
		pos.Y--;
	}
	
	else if (edamage < 0)
	{
		setColor(7);
		announcement = "Enemy healed " + to_string(-edamage) + " HP";
		write(announcement, pos);
		pos.Y--;
	}

	if (pdamage > 0)
	{
		setColor(12);
		announcement = "Enemy dealt " + to_string(pdamage) + " damage to you";
		write(announcement, pos);
		pos.Y--;
	}

	else if (pdamage < 0)
	{
		setColor(11);
		announcement = "You healed " + to_string(-pdamage) + " HP";
		write(announcement, pos);
		pos.Y--;
	}

	Sleep(300);
	setColor();
}

void Battle::setup()		//Sets up the game
{
	gameison = true;
	winStatus = false;
	generateEnemies();
	selectEnemy();

	attack = new string[5];
	defence = new string[5];
	buff = new string[5];
	debuff = new string[5];
	arrow = new string[3];
	
	arrow[0] = " * ";
	arrow[1] = "***";
	arrow[2] = " * ";

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

	buff[0] = "|--\\   |     |   |---- ";
	buff[1] = "|   >  |     |   |     ";
	buff[2] = "|--<   |     |   |--    ";
	buff[3] = "|   >  |     |   |      ";
	buff[4] = "|--/   |_____|   |      ";
	
	debuff[0] = "|\\     |--\\    |----";
	debuff[1] = "| \\    |   >   |    ";
	debuff[2] = "|  |   |--<    |--    ";
	debuff[3] = "| /    |   >   |      ";
	debuff[4] = "|/     |--/    |      ";
}

void Battle::update()	//For things which should be checked and updated constantly
{
	if (gameison) updateCtr();
	Controller();
	if(gameison) enemyAttack();
}

void Battle::draw()		//Draws frames
{
	if (gameison)
	{
		drawMap();
		drawUI();
		drawCursor();
		drawPlayer(player);
		drawEnemy(*currentEnemy);
	}
}