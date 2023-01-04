#pragma once
#include "Character.h"
#include <string>
#include "Player.h"

class Imp :public Character
{
public:
	void specialAbility(Character &ost) override;
		Imp()
		{
			HP = 40;
			attackPow = 11;
			defencePow = 5;
			attackCoef = 3;
			healthCoef = 1;
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

			numberofquotes = 1;
			attackQuotes = new string[numberofquotes];
			attackQuotes[0] = "Baaargh!";

			attackedQuotes = new string[numberofquotes];
			attackedQuotes[0] = "AAAARGH!!!";

			defenceQuotes = new string[numberofquotes];
			defenceQuotes[0] = "Grrrrrgh...";

			specialQuotes = new string[numberofquotes];
			specialQuotes[0] = "SPECIAL!!";
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

			numberofquotes = obj.numberofquotes;
			attackQuotes = new string[numberofquotes];
			attackedQuotes = new string[numberofquotes];
			defenceQuotes = new string[numberofquotes];
			specialQuotes = new string[numberofquotes];

			for (size_t i = 0; i < numberofquotes; i++)
			{
				attackQuotes[i] = obj.attackQuotes[i];
				attackedQuotes[i] = obj.attackedQuotes[i];
				defenceQuotes[i] = obj.defenceQuotes[i];
				specialQuotes[i] = obj.specialQuotes[i];
			}
		}

		~Imp()
		{
			delete[] art;
			delete[] attackedQuotes;
			delete[] attackQuotes;
			delete[] defenceQuotes;
			delete[] specialQuotes;
		}
		
		void Imp_Skıll();
		void setoac(int org) { this->originalAttackCoef = org; }
};	

class Vampire :public Character
{
	public:
		void specialAbility(Character& ost) override;
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

			numberofquotes = 1;
			attackQuotes = new string[numberofquotes];
			attackQuotes[0] = "I can smell your blood";

			attackedQuotes = new string[numberofquotes];
			attackedQuotes[0] = "You will pay for that";

			defenceQuotes = new string[numberofquotes];
			defenceQuotes[0] = "Nothing a little blood can't fix";

			specialQuotes = new string[numberofquotes];
			specialQuotes[0] = "SPECIAL!!";
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

			numberofquotes = obj.numberofquotes;
			attackQuotes = new string[numberofquotes];
			attackedQuotes = new string[numberofquotes];
			defenceQuotes = new string[numberofquotes];
			specialQuotes = new string[numberofquotes];

			for (size_t i = 0; i < numberofquotes; i++)
			{
				attackQuotes[i] = obj.attackQuotes[i];
				attackedQuotes[i] = obj.attackedQuotes[i];
				defenceQuotes[i] = obj.defenceQuotes[i];
				specialQuotes[i] = obj.specialQuotes[i];
			}
		}

		~Vampire()
		{
			delete[] art;
			delete[] attackedQuotes;
			delete[] attackQuotes;
			delete[] defenceQuotes;
			delete[] specialQuotes;
		}
};

class Cyclops :public Character
{
	public:
		void specialAbility(Character& ost) override;
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

			numberofquotes = 1;
			attackQuotes = new string[numberofquotes];
			attackQuotes[0] = "I will devour you";

			attackedQuotes = new string[numberofquotes];
			attackedQuotes[0] = "Nothing but a scratch";

			defenceQuotes = new string[numberofquotes];
			defenceQuotes[0] = "The likes of you cannot kill me";

			specialQuotes = new string[numberofquotes];
			specialQuotes[0] = "SPECIAL!!";
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

			numberofquotes = obj.numberofquotes;
			attackQuotes = new string[numberofquotes];
			attackedQuotes = new string[numberofquotes];
			defenceQuotes = new string[numberofquotes];
			specialQuotes = new string[numberofquotes];

			for (size_t i = 0; i < numberofquotes; i++)
			{
				attackQuotes[i] = obj.attackQuotes[i];
				attackedQuotes[i] = obj.attackedQuotes[i];
				defenceQuotes[i] = obj.defenceQuotes[i];
				specialQuotes[i] = obj.specialQuotes[i];
			}
		}

		~Cyclops()
		{
			delete[] art;
			delete[] attackedQuotes;
			delete[] attackQuotes;
			delete[] defenceQuotes;
			delete[] specialQuotes;
		}
};

class Demon :public Character
{
	public:
		void specialAbility(Character &ost) override;

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

			numberofquotes = 1;
			attackQuotes = new string[numberofquotes];
			attackQuotes[0] = "Let me give you a little taste of Hell";

			attackedQuotes = new string[numberofquotes];
			attackedQuotes[0] = "I won't go back to hell";

			defenceQuotes = new string[numberofquotes];
			defenceQuotes[0] = "Underworld, grant me your aid!";

			specialQuotes = new string[numberofquotes];
			specialQuotes[0] = "SPECIAL!!";
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

			numberofquotes = obj.numberofquotes;
			attackQuotes = new string[numberofquotes];
			attackedQuotes = new string[numberofquotes];
			defenceQuotes = new string[numberofquotes];
			specialQuotes = new string[numberofquotes];

			for (size_t i = 0; i < numberofquotes; i++)
			{
				attackQuotes[i] = obj.attackQuotes[i];
				attackedQuotes[i] = obj.attackedQuotes[i];
				defenceQuotes[i] = obj.defenceQuotes[i];
				specialQuotes[i] = obj.specialQuotes[i];
			}
		}

		~Demon()
		{
			delete[] art;
			delete[] attackedQuotes;
			delete[] attackQuotes;
			delete[] defenceQuotes;
			delete[] specialQuotes;
		}
};