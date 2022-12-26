#pragma once
#include "Character.h"

class Mushroom :public Character
{
	public:
		char arrmushroom[5][5];
		Mushroom()
		{
			HP = 10;
			attackPow = 1;
			attackCoef = 5;
			healthCoef = 2;
		}
	
};	

class Goblin :public Character
{
	public:
		char arrgoblin[5][5];
		Goblin()
		{
			HP = 20;
			attackPow = 3;
			attackCoef = 5;
			healthCoef = 2;
		}
};

class Orc :public Character
{
	public:
		char arrorc[5][5];
		Orc()
		{
			HP = 30;
			attackPow = 5;
			attackCoef = 5;
			healthCoef = 2;
		}
};

class Demon :public Character
{
	public:
		char arrdemon[5][5];
		Demon()
		{
			HP = 50;
			attackPow = 10;
			attackCoef = 5;
			healthCoef = 2;
		}
};