#include "Menu.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void Menu::Start()		//Function output character selection menu
{
	system("cls");
	setColor();
	COORD pos;
	string characterConfirm;
	int tempChoice;

	point:
	system("cls");
	cout << "Choose your Character (0 - 4): ";
	cin >> tempChoice;
	if (isdigit(tempChoice) == 1 && tempChoice <= 4 && 0 <= tempChoice) {
		Player* character = new Player(tempChoice);
		pos.X = 5;
		pos.Y = 4;
		drawArr(character->art, character->artsize, pos);
		cout << endl << endl << "Character name:" << character->name;
		cout << endl <<"Character HP:" << character->getMaxHP();
		cout << endl <<"Character AP:" << character->getattackPow();
	
		point2:
		cout << "\nDo you confirm character?(y/n)";
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
		cout << "Wrong input!!" << endl;
		system("pause");
		goto point;
	}
}

void Menu::End()		//Function to output game status and input user choice to play again 
{
	system("cls");
	COORD pos;
	pos.X = 70;
	pos.Y = 15;

	if (Battle::winStatus)
	{
		setColor();
		string* win{ nullptr };
		win = new string[5];
		win[0] = "W     W III N   N";
		win[1] = "W     W  I  NN  N";
		win[2] = "W  W  W  I  N N N";
		win[3] = " W W W   I  N  NN";
		win[4] = "  W W   III N   N";
		drawArr(win, 5, pos);
	}

	else
	{
		setColor(4);
		string* defeat{ nullptr };
		defeat = new string[5];
		defeat[0] = "DDD  EEEE FFFF EEEE  AA  TTTTTT";
		defeat[1] = "D  D E    F    E    A  A   TT  ";
		defeat[2] = "D  D EEE  FFF  EEE  AAAA   TT  ";
		defeat[3] = "D  D E    F    E    A  A   TT  ";
		defeat[4] = "DDD  EEEE F    EEEE A  A   TT  ";
		drawArr(defeat, 5, pos);
		
	}
	cout << setw(50);
	gotoxy(pos.X-13, pos.Y+8);
	cout << "Do you want to play again (1 to yes, 0 to no): ";
	cin >> replay;
}