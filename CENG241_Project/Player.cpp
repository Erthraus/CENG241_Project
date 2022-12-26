#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
	HP = 0;
	attackPow = 0;
	attackCoef = 0;
	healthCoef = 0;
	name = "DEFAULT";
}

Player::Player(int chc) {
	if (chc == 0) {
		HP = 50;
		attackPow = 10;
		attackCoef = 1;
		healthCoef = 1;
		name = "DefenderPoky";
	}
	if (chc == 1) {
		HP = 35;
		attackPow = 15;
		attackCoef = 1;
		healthCoef = 1;
		name = "FighterPoky";
	}
}

int Player::Buff(int )
