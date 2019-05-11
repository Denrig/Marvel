#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "Fight.h"
#include <iostream>
#include <Windows.h>
using nlohmann::json;
Fight::Fight(){
	std::vector <json> alljSon;
	std::ifstream i("characters.json");
	json j = json::parse(i);
	int k = 0;
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		
		alljSon.push_back(it.value());
		Character v= Character(alljSon[k]["id"], alljSon[k]["name"], alljSon[k]["description"], alljSon[k]["attack"], alljSon[k]["health"], alljSon[k]["isVillain"]);
		ch.addElem(v);
		k++;
	}
	alljSon.clear();
	i.close();
	i.open("planets.json");
	j = json::parse(i);
	k = 0;
	for (auto it = j.begin(); it != j.end(); ++it)
	{
		alljSon.push_back(it.value());
		pl.addElem(Planet(alljSon[k]["id"], alljSon[k]["name"], alljSon[k]["description"], alljSon[k]["modifiers"]["heroAttackModifier"], alljSon[k]["modifiers"]["heroHealthModifier"], alljSon[k]["modifiers"]["villainAttackModifier"], alljSon[k]["modifiers"]["villainHealthModifier"]));
		k++;
	}

}
Fight::~Fight(){}
Character& Fight::fight(Planet& p, Character& h, Character& v) {
	Character h1=h,v1=v;
	h1.modify(p);
	v1.modify(p);
	int d1, d2;
	do {
		d1=h1.attackE(v1);
		std::cout<< h1.getName() << " hit " << v1.getName() << " with " << d1 << " damage." << "\n";
		std::cout<<"\n" << v1.toString();
		Sleep(1000);
		d2=v1.attackE(h1);
		std::cout << v1.getName() << " hit " << h1.getName() << " with " << d2 << " damage." << "\n";
		std::cout<<"\n" << h1.toString();
		Sleep(1000);
	} while (h1.getHealth() > d2&& v1.getHealth() > d1);
		
	if (h1.getHealth() <= v1.getAttack()) 
	{		
		std::cout << v1.getName() << " hit " << h1.getName() << " with " << d2 << " damage." << "\n";
		return v;
	}
	
	else
	{
		std::cout << h1.getName() << " hit " << v1.getName() << " with " <<d1 << " damage." << "\n";
		return h;
	}
}
bool Fight::fight(Planet& p, Repo<Character>& h, Character& v) {
	Character v1 = v;
	Repo<Character> h1=h;
	int i = 0;
	for ( i = 0; i < h.getAll().size(); i++)
		h1.getAll()[i].modify(p);
	v1.modify(p);
	int d1, d2;
	do {
		for (int i = 0; i < h.getAll().size(); i++)
		{
			d1 = h1.getAll()[i].attackE(v1);
			std::cout << h1.getAll()[i].getName() << " hit " << v1.getName() << " with " << d1 << " damage." << "\n";
			Sleep(1000);
		}

		std::cout << "\n" << v1.toString();
		for (i = 0; i < h.getAll().size(); i++)
		{
			d2 = v1.attackE(h1.getAll()[i]);
			std::cout << v1.getName() << " hit " << h1.getAll()[i].getName() << " with " << d2 << " damage." << "\n";
			if (h1.getAll()[i].getHealth() < 0)
			{
				h1.delElem(h1.getAll()[i]);
				std::cout << h1.getAll()[i].getName()<<" died"<<endl;
			}

			
			Sleep(1000);
		}std::cout << "\n" << h1.getAll()[i].toString();
	} while ( h1.getAll().size() > 0 && v1.getHealth() > 0);
	if (h1.getAll().size() > 0)
		return true;
	else { return false; }


	
}
Repo<Character> Fight::getCh() {
	return ch;
}
Repo<Planet> Fight::getPl() {
	return pl;
}
Repo<Character> Fight::getVillan() {
	Repo<Character> v;
	for (int i = 0; i < ch.getAll().size(); i++) {
		if (ch.getAll()[i].getISVillain())
			v.addElem(ch.getAll()[i]);
	}
	return v;
}
Repo<Character> Fight::getHero() {
	Repo<Character> v;
	for (int i = 0; i < ch.getAll().size(); i++) {
		if (!ch.getAll()[i].getISVillain())
			v.addElem(ch.getAll()[i]);
	}
	return v;
}
Character& Fight::findChByID(int n) {
	for (int i = 0; i < ch.getAll().size(); i++) {
		if (ch.getAll()[i].getID() == n)
			return ch.getAll()[i];
	}
}
Planet& Fight::findPlByID(int n) {
	for (int i = 0; i < ch.getAll().size(); i++) {
		if (ch.getAll()[i].getID() == n)
			return pl.getAll()[i];
		
	}
}