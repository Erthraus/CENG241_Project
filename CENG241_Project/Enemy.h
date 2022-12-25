#pragma once
#include "Charachter.h"
class Enemy:public Charachter
{
public:
	Enemy(int HP,int attackPow) {
		this->HP = HP;
	}
};

