#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::Start()		//Function output character selection menu
{
	setColor();
	COORD pos;
	string characterConfirm;
	int tempChoice;
	point:
	system("cls");
	cout << "Choose your Character (0 - 3): ";
	cin >> tempChoice;
	Player* character = new Player(tempChoice);
	if (tempChoice < 4) {
		pos.X = 5;
		pos.Y = 4;
		drawArr(character->art, character->artsize, pos);
		cout << endl;
		cout << "Character name:" << character->name << endl;
		cout << "Character HP:" << character->getMaxHP() << endl;
		cout << "Character AP:" << character->getattackPow() << endl;
		point2:
		cout << "Do you confirm character?(y/n)";
		cin >> characterConfirm;
		if (characterConfirm == "y") {
			characterChoice = tempChoice;
			system("cls");
		}
		else if (characterConfirm == "n") {
			system("cls");
			delete character;
			goto point;

		}
		else {
			cout << "Wrong input!" << endl;
			system("pause");
			goto point2;
		}
	}
	
	else {
		cout << "Wrong input!" << endl;
		delete character;
		system("pause");
		goto point;
	}
}

void Menu::End()		//Function to output game status and input user choice to play again 
{
	system("cls");

	if (Battle::winStatus)
	{
		setColor();
		cout << "VICTORY" << endl;
	}

	else
	{
		setColor(4);
		cout << "DEFEAT" << endl;
	}

	cout << "Do you want to play again (1 to yes, 0 to no): ";
	cin >> replay;
}