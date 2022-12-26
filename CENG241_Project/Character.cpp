#include "Character.h"
#include<iostream>
#include <cstdlib>

void Character::Attack(Character &target) {
	int randomAttack = attackPow + rand() % (attackCoef + 1);
	changeHP(-1 * randomAttack, target);
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


