#pragma once
#include <cstring>
#include <iostream>
#include "Planet.h"
using namespace std;
class Character {
	private:
		int id;
		string name;
		string desc;
		bool isVillain;
		int attack;
		int health;
	public:
		Character();
		Character(int id, string name, string desc, int attack, int health,bool isVillain);
		Character(const Character& x);
		~Character();
		Character& operator=(const Character& x);
		bool operator==(const Character& x);
		string toString();
		void setAttack(int n);
		int attackE(Character& c);
		int getID();
		string getName();
		int getAttack();
		int getHealth();
		bool getISVillain();
		void modify(Planet& p);
};