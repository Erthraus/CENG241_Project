#include "Character.h"
#include<iostream>
#include<time.h>

int Character::Attack(Character &target) {
	int randomAttack = attackPow + rand() % (attackCoef + 1);
	return randomAttack;
}

int Character::decDMG() {
	int randomDec = rand() % (attackPow * 30 / 100) + 1;
	for (int i = 0; i < 2; i++) {
		attackPow -= randomDec;
	}
	return randomDec;
}

int Character::incHP() {
	int randomInc = rand() % (HP * 10 / 100) + 1;
	HP += randomInc;
	return randomInc;
}

int Character::takenDMG() {
	HP -= attackPow;
	return HP;
}


