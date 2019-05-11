#pragma once
#include <vector>
#include "Character.h"
#include "Planet.h"
#include "Repo.h"

using namespace std;
class Fight {
private:
	Repo<Character> ch;
	Repo<Planet> pl;
public:
	Fight();
	~Fight();
	Repo<Character> getCh();
	Repo<Planet> getPl();
	Character& fight(Planet& p, Character& h, Character& v);
	bool fight(Planet& p, Repo<Character>& h, Character& v);
	Repo<Character> getVillan();
	Repo<Character> getHero();
	Character& findChByID(int n);
	Planet& findPlByID(int n);
	
};