#pragma once
#include <iostream>
#include "Character.h"
#include <string>

using namespace std;

class Player: public Character
{
	public:
		bool isBuffed = false;
		int buffCtr = 0;
		int buffCoef = 50;
		int debuffCoef = 30;

		void Buff();
		void Debuff(Character& target);
		string name;
		bool isburning = 0;
		int sitct = 0;
		void burn() {
			if (isburning == 1 && sitct <=2) {
				if(getHP() > 10)
					setHP(getHP() - 10);
				sitct++;
			}
			else if (isburning == 1 && sitct == 3) {
				isburning = 0;
				sitct = 0;
			}
		}
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
				HP = 100;
				attackPow = 15;
				defencePow = 30;
				attackCoef = 1;
				healthCoef = 2;
				name = "DefenderPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
				artsize = 20;
				art = new string[artsize];
				art[0] =  "  ,   A           {}";
				art[1] =  " / \\, | ,        .--.";
				art[2] =  "|    =|= >      /.--.\\";
				art[3] =  " \\ /` | `       |====|";
				art[4] =  "  `   |         |`::`|";
				art[5] =  "      |     .-;`\\..../`;_.-^-._";
				art[6] =  "     /\\\\/  /  |...::..|`   :   `|";
				art[7] =  "     |:'\\ |   /'''::''|   .:.   |";
				art[8] =  "      \\ /\\;-,/\\   ::  |..:::::..|";
				art[9] =  "      |\\ <` >  >._::_.| ':::::' |";
				art[10] = "      | `\"\"`  /   ^^  |   ':'   |";
				art[11] = "      |       |       \\    :    /";
				art[12] = "      |       |        \\   :   /";
				art[13] = "      |       |___/\\___|`-.:.-`";
				art[14] = "      |        \\_ || _/    `";
				art[15] = "      |        <_ >< _>";
				art[16] = "      |        |  ||  |";
				art[17] = "      |        |  ||  |";
				art[18] = "      |       _\\.:||:./_";
				art[19] = "      |      /____/\\____\\";
			}
			else if (chc == 1) {				
				HP = 50;
				attackPow = 20;
				defencePow = 20;
				attackCoef = 1;
				healthCoef = 3;
				name = "FighterPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
				artsize = 20;
				art = new string[artsize];
				art[0] =  " /\\			{}				";
				art[1] =  " ||          .--.				";
				art[2] =  " ||         /.--.\\			";
				art[3] =  " ||         |====|			";
				art[4] =  " ||         |`::`|			";
				art[5] =  "_||_    .-;`\\..../`;_.-^-._	";
				art[6] =  " /\\\\   /  |...::..|`   :   `|	";
				art[7] =  " |:'\\ |   /'''::''|   .:.   |	";
				art[8] =  "  \\ /\\;-,/\\   ::  |..:::::..|	";
				art[9] =  "   \\ <` >  >._::_.| ':::::' |	";
				art[10] = "    `""` /   ^^  |   ':'   | ";
				art[11] = "         |       \\    :    / ";
				art[12] = "         |        \\   :   /	";
				art[13] = "         |___/\\___|`-.:.-`	";
				art[14] = "          \\_ || _/    `		";
				art[15] = "          <_ >< _>			";
				art[16] = "          |  ||  |			";
				art[17] = "          |  ||  |			";
				art[18] = "         _\\.:||:./_			";
				art[19] = "		   /____/\\____\\			";

			}
			else if (chc == 2) {
				HP = 55;
				attackPow = 15;
				defencePow = 10;
				attackCoef = 2;
				healthCoef = 2;
				name = "ArcherPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;

				artsize = 19;
				art = new string[artsize];
				art[0] = "										  / -----------| .					";
				art[1] =  "       \\\\                             /			     | .				";
				art[2] =  "         \\\\                         /					   |\\				";
				art[3] =  "          \\|                      /					     |\\				";
				art[4] =  "         \\#####\\                /						     ||				";
				art[5] =  "     ==###########>           /				 			 ||				";
				art[6] =  "      \\##==      \\	      /								 ||				";
				art[7] =  " ______ =       =|__		/___							 ||				";
				art[8] =  " ,--' ,----`-,__ ___/'----,-`-==============================##==========> ";
				art[9] =  " \\              '        ##_______ ______   ______,--,____,=##,__			";
				art[10] = " `,    __==    ___,-,__,--'#'  ==='      `-'              | ##,-/		";
				art[11] = "  `-,____,---'       \\####\\              |        ____,--\\_##,/			";
				art[12] = "      #_              |##   \\  _____,---==,__,---'         ##			";
				art[13] = "      #              ]===--==\\                            ||				";
				art[14] = "      #,             ]         \\                          ||				";
				art[15] = "       #_            |           \\                        ||				";
				art[16] = "        ##_       __/'             \\                     /||				";
				art[17] = "         ####='     |                \\                 |/				";
				art[18] = "      ###=======]                       \\ ---------- /|.					";

			}
			else if (chc == 3) {
				HP = 50;
				attackPow = 10;
				defencePow = 20;
				attackCoef = 2;
				healthCoef = 2;
				name = "WizardPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
				artsize = 20;
				art = new string[artsize];
				art[0] =  "              _,._      ";
				art[1] =  "  .||,       /_ _\\\\     ";
				art[2] =  " \\.`',/      |'L'| |    ";
				art[3] =  " = ,. =      | -,| L    ";
				art[4] =  " / || \\    ,-'\\\"/,'`.   ";
				art[5] =  "   ||     ,'   `,,. `.  ";
				art[6] =  "   ,|____,' , ,;' \\| |  ";
				art[7] =  "  (3|\\    _/|/'   _| |  ";
				art[8] =  "   ||/,-''  | >-'' _,\\\\ ";
				art[9] =  "   ||'      ==\\ ,-'  ,' ";
				art[10] = "   ||       |  V \\ ,|   ";
				art[11] = "   ||       |    |` |   ";
				art[12] = "   ||       |    |   \\  ";
				art[13] = "   ||       |    \\    \\ ";
				art[14] = "   ||       |     |    \\";
				art[15] = "   ||       |      \\_,-'";
				art[16] = "   ||       |___,,--\")_\\";
				art[17] = "   ||         |_|   ccc/";
				art[18] = "   ||        ccc/       ";
				art[19] = "========================";
			}
			else if (chc == 4) {
				HP = 800;
				attackPow = 60;
				defencePow = 40;
				attackCoef = 1;
				healthCoef = 1;
				name = "TankPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
				artsize = 21;
				art = new string[artsize];
				art[0] =  "     .      .";
				art[1] =  "     |\\____/|";
				art[2] =  "    (\\|----|/)";
				art[3] =  "     \\ 0  0 /";
				art[4] =  "      |    |";
				art[5] =  "   ___/\\../\\____";
				art[6] =  "  /     --       \\";
				art[7] =  " /  \\         /   \\";
				art[8] =  "|    \\___/___/(   |";
				art[9] =  "\\   /|  }{   | \\  )";
				art[10] = " \\  ||__}{__|  |  |";
				art[11] = "  \\  |;;;;;;;\\  \\ / \\_______";
				art[12] = "   \\ /;;;;;;;;| [,,[|======'";
				art[13] = "     |;;;;;;/ |     /";
				art[14] = "     ||;;|\\   |";
				art[15] = "     ||;;/|   /";
				art[16] = "     \\_|:||__|";
				art[17] = "      \\ ;||  /";
				art[18] = "      |= || =|";
				art[19] = "      |= /\\ =|";
				art[20] = "      /_/  \\_\\";
			}
		}
		
		~Player() {
			delete[] art;
		}
};

