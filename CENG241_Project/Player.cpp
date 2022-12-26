#include "Player.h"
#include <iostream>

using namespace std;

void Player::Buff()
{
	attackCoef = attackCoef * 120 / 100;
}

void Player::Debuff(Character &target)
{
	target.setattackCoef(target.getattackCoef() * 50 / 100);
}
