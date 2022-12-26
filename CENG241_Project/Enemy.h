#pragma once
#include "Character.h"
#include <string>

class Imp :public Character
{
public:
		Imp()
		{
			HP = 10;
			attackPow = 1;
			defencePow = 1;
			attackCoef = 5;
			healthCoef = 2;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = 9;
			art = new string[artsize];

			art[0] = "   |\\     ____";
			art[1] = "   | \\.-./ .-'";
			art[2] = "    \\ _  _(   ";
			art[3] = "    | .)(./   ";
			art[4] = "    |   \\(    ";
			art[5] = "    |     \\   ";
			art[6] = "    |  \\vvv   ";
			art[7] = "    |  |__    ";
			art[8] = "   /      `-. ";
		}
		Imp(const Imp& obj)
		{
			HP = obj.HP;
			attackPow = obj.attackPow;
			defencePow = obj.defencePow;
			attackCoef = obj.attackCoef;
			healthCoef = obj.healthCoef;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = obj.artsize;

			art = new string[artsize];

			for (size_t i = 0; i < artsize; i++)
			{
				art[i] = obj.art[i];
			}
		}

		~Imp()
		{
			delete[] art;
		}
	
};	

class Vampire :public Character
{
	public:
		
		Vampire()
		{
			HP = 20;
			attackPow = 3;
			defencePow = 3;
			attackCoef = 5;
			healthCoef = 2;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = 9;
			art = new string[artsize];
			art[0] = "  //^\\   /^\\\\  ";
			art[1] = " ;/ ~_\\ /_~ \\; ";
			art[2] = " |  / \\Y/ \\  | ";
			art[3] = "(,  \\0/ \\0/  ,)";
			art[4] = " |   /   \\   | ";
			art[5] = " | (_\\._./_) | ";
			art[6] = "  \\ \\v-.-v/ /  ";
			art[7] = "   \\ `===' /   ";
			art[8] = "    `-----`    ";
		}

		Vampire(const Vampire& obj)
		{
			HP = obj.HP;
			attackPow = obj.attackPow;
			defencePow = obj.defencePow;
			attackCoef = obj.attackCoef;
			healthCoef = obj.healthCoef;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = obj.artsize;

			art = new string[artsize];

			for (size_t i = 0; i < artsize; i++)
			{
				art[i] = obj.art[i];
			}
		}

		~Vampire()
		{
			delete[] art;
		}
};

class Cyclops :public Character
{
	public:

		Cyclops()
		{
			HP = 30;
			attackPow = 5;
			defencePow = 1;
			attackCoef = 5;
			healthCoef = 2;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = 20;
			art = new string[artsize];
			art[0] =  "           _......._			  ";
			art[1] =  "       .-'.'.'.'.'.'.`-.		  ";
			art[2] =  "     .'.'.'.'.'.'.'.'.'.`.	  ";
			art[3] =  "    /.'.'               '.\\	  ";
			art[4] =  "    |.'    _.--...--._     |   ";
			art[5] =  "    \\    `._.-.....-._.'   /	  ";
			art[6] =  "    |     _..- .-. -.._   |    ";
			art[7] =  " .-.'    `.   ((@))  .'   '.-. ";
			art[8] =  "( ^ \\      `--.   .-'     / ^ )";
			art[9] =  " \\  /         .   .       \\  / ";
			art[10] = " /          .'     '.  .-    \\ ";
			art[11] = "( _.\\    \\ (_`-._.-'_)    /._\\)";
			art[12] = " `-' \\   ' .--.          / `-' ";
			art[13] = "     |  / /|_| `-._.'\\   |	  ";
			art[14] = "     |   |       |_| |   /-.._ ";
			art[15] = " _..-\\   `.--.______.'  |	  ";
			art[16] = "      \\       .....     |	  ";
			art[17] = "       `.  .'      `.  /		  ";
			art[18] = "         \\           .'		  ";
			art[19] = "          `-..___..-`		  ";
		}

		Cyclops(const Cyclops& obj)
		{
			HP = obj.HP;
			attackPow = obj.attackPow;
			defencePow = obj.defencePow;
			attackCoef = obj.attackCoef;
			healthCoef = obj.healthCoef;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = obj.artsize;

			art = new string[artsize];

			for (size_t i = 0; i < artsize; i++)
			{
				art[i] = obj.art[i];
			}
		}

		~Cyclops()
		{
			delete[] art;
		}
};

class Demon :public Character
{
	public:

		Demon()
		{
			HP = 50;
			attackPow = 10;
			defencePow = 1;
			attackCoef = 5;
			healthCoef = 2;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = 15;
			art = new string[artsize];
			art[0] =  "                 /\\     ";
			art[1] =  "                 ||     ";
			art[2] =  "   ____ (((+))) _||_    ";
			art[3] =  "  /.--.\\  .-.  /.||.\\   ";
			art[4] =  " /.,   \\\\(0.0)// || \\  ";
			art[5] =  "/;` ; / \\  |   m ||/    ";
			art[6] =  "|:   \\ \\__`:`____||__:| ";
			art[7] =  "|:    \\__ \\T/ (@~)(~@)| ";
			art[8] =  "|:    _/|     |\\_\\/  :| ";
			art[9] =  "|:   /  |     |  \\   :| ";
			art[10] = "|'  /   |     |   \\  '| ";
			art[11] = " \\_/    |     |    \\_/  ";
			art[12] = "        |     |		   ";
			art[13] = "        |_____|		   ";
			art[14] = "        |_____|         ";
		}

		Demon(const Demon& obj)
		{
			HP = obj.HP;
			attackPow = obj.attackPow;
			defencePow = obj.defencePow;
			attackCoef = obj.attackCoef;
			healthCoef = obj.healthCoef;
			maxHP = HP;
			originalAttackCoef = attackCoef;
			artsize = obj.artsize;

			art = new string[artsize];

			for (size_t i = 0; i < artsize; i++)
			{
				art[i] = obj.art[i];
			}
		}

		~Demon()
		{
			delete[] art;
		}
};