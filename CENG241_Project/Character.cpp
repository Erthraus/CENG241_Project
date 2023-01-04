#include "Character.h"
#include<iostream>
#include <cstdlib>
#include <windows.h>

void Character::Attack(Character &target) {
	int randomAttack = attackPow + rand() % (attackCoef + 1);
	changeHP(randomAttack, target);
	if (target.getHP() < 0)
		target.setHP(0);
}

void Character::Defence() {
	int randomHeal =  defencePow + rand() % (healthCoef + 1);
	HP += randomHeal;
	if (HP > maxHP)
		HP = maxHP;
}

void Character::changeHP(int val, Character &target) {
	target.setHP(target.getHP() - val);
}

string Character::Quote(int a)
{
	int quote = rand() % (numberofquotes);

	if (a == 3)
		return specialQuotes[quote];

	else if (a == 2)
		return attackQuotes[quote];

	else if (a == 1)
		return attackedQuotes[quote];

	else
		return defenceQuotes[quote];
}

void Character::specialAbility(Character& ost)
{
	return;
}

void Character::Burn() {
	if (isburning == true && burnCtr > 0) {
		if (HP > 10)
			this->setHP(HP - 10);
		burnCtr--;
	}

	else
		isburning = false;
}