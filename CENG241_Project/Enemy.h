#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	string enemy[4];
	char arr[5][10];
	//virtual int Attack();
	Enemy(int attackCoef, int healthCoef);
};

class Bat: public Enemy
{

};
