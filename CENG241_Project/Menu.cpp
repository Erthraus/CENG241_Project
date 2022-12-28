#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::Start()		//Function output character selection menu
{
	setColor();
	cout << "Choose your Character (0 - 4): ";
	cin >> characterChoice;
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