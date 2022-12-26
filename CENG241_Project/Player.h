#pragma once
#include <iostream>
#include "Character.h"
#include <string>

using namespace std;
class Player: public Character
{
public:
	int Buff();
	int Debuff();
	string name;

	Player();
	Player(int chc);
};

