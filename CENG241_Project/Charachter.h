#pragma once
#include<string>
using namespace std;
class Charachter
{
protected:
	int HP=10;
	int attackPow=1;
	int attackCoef;
	int healthCoef;
public:
	Charachter();
	int incHP();//heal-buff
	int decDMG();//damage reduction-debuff
	int takenDMG();
	virtual int Attack()=0;//create attack power
	void setHP(int HP) { this->HP = HP; }
	void setattackCoef(int attackCoef) { this->attackCoef = attackCoef; }
	void sethealthCoef(int healthCoef) { this->healthCoef = healthCoef; }
	void setattackPow(int attackPow) { this->attackPow = attackPow; }
	int getHP() { return HP; }
	int getattackCoef() { return attackCoef; }
	int gethealthCoef() { return healthCoef; }
	int getattackPow() { return attackPow; }

};

