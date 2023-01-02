#include "Menu.h"
#include <iostream>
#include <windows.h>


using namespace std;

void Menu::Start()		//Function output character selection menu
{
	setColor();
	COORD pos;
	string characterConfirm;
	int tempChoice;
	point:
	cout << "Choose your Character (0 - 3): ";
	cin >> tempChoice;
	switch (tempChoice) {
		case 0:
			pos.X = 4;
			pos.Y = 4;
			drawArr(Player(0).art, Player(0).artsize, pos);
			cout << endl;
			cout << "Character name:" << Player(0).name << endl;
			cout << "Character HP:" << Player(0).getMaxHP() << endl;
			cout << "Character AP:" << Player(0).getattackPow() << endl;
			cout << "Do you confirm character?(y/n)";
			cin >> characterConfirm;
			if (characterConfirm == "y") {
				characterChoice = tempChoice;
			}
			else if (characterConfirm == "n") {
				system("cls");
				goto point;
				
			}
			else {
				cout << "Wrong input!" << endl;
				goto point;
			}
				
			break;

		default:
			cout << "Wrong input!" << endl;
			goto point;
			break;
	}
	
	
}

void Menu::End()		//Function to output game status and input user choice to play again 
{
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