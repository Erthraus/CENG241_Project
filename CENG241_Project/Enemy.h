#pragma once
#include "Charachter.h"
class Enemy:public Charachter
{
public:
	char arr[][10];
	Enemy() {}
	int randomEnemy();
};

