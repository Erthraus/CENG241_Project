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
		int debuffCoef = 50;

		void specialAbility(Character& ost) override;
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
				HP = 200;
				attackPow = 25;
				defencePow = 30;
				attackCoef = 15;
				healthCoef = 20;
				buffCoef = 50;
				debuffCoef = 30;
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
				HP = 100;
				attackPow = 50;
				defencePow = 20;
				attackCoef = 20;
				healthCoef = 10;
				buffCoef = 100;
				debuffCoef = 10;
				name = "FighterPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;
				artsize = 20;
				art = new string[artsize];
				art[0] =  "      _,.";
				art[1] =  "    ,` -.)";
				art[2] =  "   ( _/-\\\\-._";
				art[3] =  "  /,|`--._,-^|            ,";
				art[4] =  "  \\_| |`-._/||          ,'|";
				art[5] =  "    |  `-, / |         /  /";
				art[6] =  "    |     || |        /  /";
				art[7] =  "     `r-._||/   __   /  /";
				art[8] =  " __,-<_     )`-/  `./  /";
				art[9] =  "'  \\   `---'   \\   /  /";
				art[10] = "    |           |./  /";
				art[11] = "    /           //  /";
				art[12] = "\\_/' \\         |/  /";
				art[13] = " |    |   _,^-'/  /";
				art[14] = " |    , ``  (\\/  /_";
				art[15] = "  \\,.->._    \\X-=/^";
				art[16] = "  (  /   `-._//^`";
				art[17] = "   `Y-.____(__}";
				art[18] = "    |     {__)";
				art[19] = "          ()";

			}
			else if (chc == 2) {
				HP = 80;
				attackPow = 70;
				defencePow = 20;
				attackCoef = 30;
				healthCoef = 20;
				buffCoef = 50;
				debuffCoef = 50;
				name = "CentaurPoky";
				maxHP = HP;
				originalAttackCoef = attackCoef;

				artsize = 21;
				art = new string[artsize];
				art[0] =  " *                       *";
				art[1] =  "    *                 *";
				art[2] =  "   )       (\\___/)     (";
				art[3] =  "* /(       \\ (. .)     )\\ *";
				art[4] =  "  # )      c\\   >'    ( #";
				art[5] =  "   '         )-_/      '";
				art[6] =  " \\\\|,    ____| |__    ,|//";
				art[7] =  "   \ )  (  `  ~   )  ( /";
				art[8] =  "    #\\ / /| . ' .) \\ /#";
				art[9] =  "    | \\ / )   , / \\ / |";
				art[10] = "     \\,/ ;;,,;,;   \\,/";
				art[11] = "      _,#;,;;,;,";
				art[12] = "     /,i;;;,,;#,;";
				art[13] = "    //  %;;,;,;;,;";
				art[14] = "   ((    ;#;,;%;;,,";
				art[15] = "  _//     ;,;; ,#;,";
				art[16] = " /_)      #,;    ))";
				art[17] = "         //      \\|_";
				art[18] = "         \\|_      |#\\";
				art[19] = "          |#\\      -\"";
				art[20] = "           -\"";

			}
			else if (chc == 3) {
				HP = 100;
				attackPow = 40;
				defencePow = 25;
				attackCoef = 20;
				healthCoef = 25;
				buffCoef = 60;
				debuffCoef = 40;
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
				attackPow = 100;
				defencePow = 50;
				attackCoef = 10;
				healthCoef = 10;
				buffCoef = 20;
				debuffCoef = 20;
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

