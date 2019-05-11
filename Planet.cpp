#include "Planet.h"
Planet::Planet() {
	id = -1;
}
Planet::Planet(int id, string name, string desc, int hAM, int hHM, int vAM, int vHM) {
	this->id = id;
	this->name = name;
	this->desc = desc;
	this->hAM = hAM;
	this->hHM = hHM;
	this->vAM = vAM;
	this->vHM = vHM;
}
Planet::Planet(const Planet& x) {
	if (this != &x) {
		this->id = x.id;
		this->name = x.name;
		this->desc = x.desc;
		this->hAM = x.hAM;
		this->hHM = x.hHM;
		this->vAM = x.vAM;
		this->vHM = x.vHM;
	}
}
Planet::~Planet(){}
Planet& Planet::operator=(const Planet& x) {
	this->id = x.id;
	this->name = x.name;
	this->desc = x.desc;
	this->hAM = x.hAM;
	this->hHM = x.hHM;
	this->vAM = x.vAM;
	this->vHM = x.vHM;
	return *this;
}
bool Planet::operator==(const Planet& x) {
	if (this->id == x.id &&
		this->name == x.name)
		return true;
	return false;
}
string Planet::toString(){

	string s = "";
	s =+"Name:" + name + "\n" + "Desc:" + desc + "\n"; 
	return s;
}
int Planet::getID() {
	return id;
}
void Planet::sethAM(int n) {
	hAM = n;
}
void Planet::sethHM(int n) {
	this->hHM = n;
}
void Planet::setvAM(int n) {
	vAM = n;
}
void Planet::setvHM(int n) {
	this->vHM = n;
}
int Planet::gethAM() {
	return hAM;
}
int Planet::gethHM() {
	return hHM;
}
int Planet::getvAM() {
	return vAM;
}
int Planet::getvHM() {
	return vHM;
}
