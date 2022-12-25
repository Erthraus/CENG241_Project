#pragma once
#include "Charachter.h"

class Enemy:public Charachter
{
public:
	string enemy[4];
	char arr[][10];
	virtual int Attack();
	Enemy(int attackCoef, int healthCoef);
};

