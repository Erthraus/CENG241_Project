#include "Charachter.h"
#include<iostream>
#include<time.h>

int Charachter::Attack() {
	attackPow *= attackCoef;
	randomAttack = rand() % attackPow + 1;
}

int Charachter::decDMG() {
	int randomDec = rand() % (attackPow * 30 / 100) - 1;
	for (int i = 0; i < 2; i++) {
		attackPow -= randomDec;
	}
}

int Charachter::incHP() {
	int randomInc = rand() % (HP * 10 / 100) - 1;
	HP += randomInc;
}

int Charachter::takenDMG() {
	HP -= randomAttack;
}


