#pragma once
#include "Character.h"
#include <string>

class Mushroom :public Character
{
	public:
		Mushroom()
		{
			art[0] =	"            ▓▓▓▓▓▓▓▓            ";
			art[1] =	"          ▓▓▒▒▒▒▒▒▒▒▓▓          ";
			art[2] =	"        ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒        ";
			art[3] =	"      ▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓      ";
			art[4] =	"    ▓▓████▒▒▒▒▒▒▒▒▒▒▒▒████▓▓    ";
			art[5] =	"  ░░▒▒▓▓░░██▒▒▒▒▒▒▒▒██░░▓▓▒▒░░  ";
			art[6] =	"  ▓▓▒▒▓▓  ████████████  ▒▒▒▒▓▓  ";
			art[7] =	"▓▓▒▒▒▒▓▓  ██  ▓▓▒▒  ██  ▒▒▒▒▒▒▒▒";
			art[8] =	"▒▒▒▒▒▒▓▓      ▓▓▒▒      ▒▒▒▒▒▒▒▒";
			art[9] =	"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
			art[10] =	"  ▓▓▒▒▒▒▓▓░░░░░░░░░░░░▒▒▒▒▒▒▓▓  ";
			art[11] =	"        ░░░░░░░░░░░░░░░░        ";
			art[12] =	"    ████░░░░░░░░░░░░░░░░████    ";
			art[13] =	"  ██████████░░░░░░░░██████████  ";
			art[14] =	"  ████████████░░░░████████████  ";
			art[15] =	"  ░░██████████    ██████████░░  ";
			
			HP = 10;
			attackPow = 1;
			attackCoef = 5;
			healthCoef = 2;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = 16;
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
			maxHP = HP;
			originalAttackCoef = attackCoef;
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
			maxHP = HP;
			originalAttackCoef = attackCoef;
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
			maxHP = HP;
			originalAttackCoef = attackCoef;
		}
};