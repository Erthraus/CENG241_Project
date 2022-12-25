#pragma once
#include <iostream>
#include "Charachter.h"
#include <string>

using namespace std;
class Player: public Charachter
{
public:
	int Buff();
	int Debuff();
	string name;

	Player();
	Player(int chc);
};

