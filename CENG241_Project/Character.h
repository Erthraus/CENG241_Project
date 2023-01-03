#pragma once
#include<string>

using namespace std;

class Character
{
protected:
	int HP;
	int maxHP;
	int attackPow;
	int attackCoef;
	int originalAttackCoef;
	int defencePow;
	int healthCoef;

public:
	Character() = default;
	Character(const Character& obj) = default;

	//virtual void specialAbility();
	void Attack(Character& target);
	void changeHP(int val, Character& target);
	void Defence();
	void setHP(int HP) { this->HP = HP; }
	void setattackCoef(int attackCoef) { this->attackCoef = attackCoef; }
	void sethealthCoef(int healthCoef) { this->healthCoef = healthCoef; }
	void setattackPow(int attackPow) { this->attackPow = attackPow; }
	int getHP() { return HP; }
	int getattackCoef() { return attackCoef; }
	int getOriginalAttackCoef() { return originalAttackCoef; }
	int getMaxHP() { return maxHP; }
	int gethealthCoef() { return healthCoef; }
	int getattackPow() { return attackPow; }
	int artsize;
	bool isDebuffed = false;
	int debuffCtr = 0;

	string* art;
	string* attackQuote;
	string* defenceQuote;
};

