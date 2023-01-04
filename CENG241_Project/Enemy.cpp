#include "Enemy.h"
#include "Character.h"
#include<iostream>
#include<time.h>
#include "Player.h"
#include "Battle.h"
#include "Scene.h"

void Imp::specialAbility(Character& ost) { // Give more dmg if player is below specific hp
		this->attackPow += 25;
		this->Attack(ost);
		this->attackPow -= 25;
}

void Cyclops::specialAbility(Character& ost){ //Overheal
	this->defencePow += 30;
	this->Defence();
	this->defencePow -= 30;
}

void Demon::specialAbility(Character& ost,Player& op) { // Burning Player
	if (op.isburning == 0 ) {
		op.isburning = 1;
		op.sitct = 0;
		op.burn();
	}
	else if (op.isburning == 1 )
		op.burn();
}

void Vampire::specialAbility(Character& ost) { // Spell Vamp
	this->Attack(ost);
	this->HP += 15;
	if (HP > maxHP)
		HP = maxHP;
}