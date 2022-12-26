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

		Player() 
		{
			HP = 0;
			attackPow = 0;
			attackCoef = 0;
			healthCoef = 0;
			name = "DEFAULT";
			maxHP = HP;
			originalAttackCoef = attackCoef;
		}

		Player(int chc) 
		{
			if (chc == 0) {
				HP = 50;
				attackPow = 10;
				attackCoef = 1;
				healthCoef = 1;
				name = "DefenderPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
			}
			if (chc == 1) {
				HP = 35;
				attackPow = 15;
				attackCoef = 1;
				healthCoef = 1;
				name = "FighterPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
			}
		}
};

