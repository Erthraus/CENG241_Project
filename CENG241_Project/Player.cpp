#include "Player.h"
#include <iostream>

using namespace std;

void Player::Buff()
{
	if(!isBuffed)
		attackCoef = attackCoef * (buffCoef + 100) / 100;
}

void Player::Debuff(Character &target)
{
	if(!target.isDebuffed)
		target.setattackCoef(target.getattackCoef() * (100 - debuffCoef) / 100);
}

void Player::specialAbility(Character& ost) { 
	return;
}
