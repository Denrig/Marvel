#include "Character.h"
#include <stdlib.h>
Character::Character() {
	id = -1;
}
Character::Character(int id, string name, string desc, int attack, int health,bool isVillain) {
	this->id = id;
	this->name = name;
	this->desc = desc;
	this->attack = attack;
	this->health = health;
	this->isVillain = isVillain;
}
Character::~Character(){}
Character::Character(const Character& x) {
	if (this != &x) {
		this->id = x.id;
		this->name = x.name;
		this->desc = x.desc;
		this->attack = x.attack;
		this->health = x.health;
		this->isVillain = x.isVillain;
	}
}
bool Character::operator==(const Character& x) {
	if (this->id == x.id &&
		this->name == x.name)
		return true;
	return false;
}
Character& Character:: operator=(const Character& x) {
	this->id = x.id;
	this->name = x.name;
	this->desc = x.desc;
	this->attack = x.attack;
	this->health = x.health;
	this->isVillain = x.isVillain;
	return *this;
}
void Character::setAttack(int n) {
	this->attack = n;
}
string Character::toString() 
	{	char* b=new char[50];
		
		string strr;
		string s = "";
		s ="Name:" + name + "\n" + "Desc:" + desc + "\n";
		snprintf(b, 10, "%d", attack);
		 strr = string(b);
		s += "Attack:" + strr + "\n";
		snprintf(b, 10, "%d",health);
		strr = string(b);
		s += "Health:" + strr+"\n"+"\n";
		delete[] b;
		b = NULL;
		return s;
	}
void Character::modify(Planet& p) {
	if (isVillain) {
		attack += p.getvAM();
		health += p.getvHM();
	}
	else {
		attack += p.gethAM();
		health += p.gethHM();
	}
}
int Character::attackE(Character& n) {
	int chance,damage;
	chance = rand() % 35+65;
	damage = (chance * attack) / 100;
	n.health -= damage;
	return damage;
}
int Character::getID() {
	return this->id;
}
string Character::getName() {
	return name;
}
int Character::getAttack() {
	return attack;
}
int Character::getHealth() {
	return health;
}
bool Character::getISVillain() {
	return isVillain;
}