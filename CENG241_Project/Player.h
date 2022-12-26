#pragma once
#include <iostream>
#include "Character.h"
#include <string>

using namespace std;

class Player: public Character
{
	public:
		void Buff();
		void Debuff(Character& target);
		string name;

		Player();
		Player(int chc);
};

