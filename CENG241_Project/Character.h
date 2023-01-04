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
	int numberofquotes = 0;

public:
	Character() = default;
	Character(const Character& obj) = default;

	virtual void specialAbility(Character& ost) = 0;
	string Quote(int a);
	void Attack(Character& target);
	void changeHP(int val, Character& target);
	void Defence();
	void Burn();
	
	void setHP(int HP) { this->HP = HP; }
	void setattackCoef(int attackCoef) { this->attackCoef = attackCoef; }
	void sethealthCoef(int healthCoef) { this->healthCoef = healthCoef; }
	void setattackPow(int attackPow) { this->attackPow = attackPow; }

	int getDefencePow() { return defencePow; }
	int getHP() { return HP; }
	int getattackCoef() { return attackCoef; }
	int getOriginalAttackCoef() { return originalAttackCoef; }
	int getMaxHP() { return maxHP; }
	int gethealthCoef() { return healthCoef; }
	int getattackPow() { return attackPow; }
	
	int artsize;
	bool isDebuffed = false;
	int debuffCtr = 0;
	bool isburning = false;
	int burnCtr = 0;

	string* art{ nullptr };
	string* attackQuotes{ nullptr };
	string* defenceQuotes{ nullptr };
	string* attackedQuotes{ nullptr };
	string* specialQuotes{ nullptr };
};

