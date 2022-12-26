#include "Enemy.h"
#include "Charachter.h"
#include<iostream>
#include<time.h>

Enemy::Enemy(int attackCoef, int healthCoef) {
	this->attackCoef = attackCoef;
	this->healthCoef = healthCoef;
}
