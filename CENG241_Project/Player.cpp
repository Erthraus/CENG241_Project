#include "Player.h"
#include <iostream>

using namespace std;

void Player::Buff()
{
	attackCoef = attackCoef * (buffCoef + 100) / 100;
}

void Player::Debuff(Character &target)
{
	target.setattackCoef(target.getattackCoef() * (100 - debuffCoef) / 100);
}
