#pragma once
#include <iostream>
using namespace std;
class Planet {
private:
	int id;
	string name;
	string desc;
	int hAM;
	int hHM;
	int vAM;
	int vHM;
public:
	Planet();
	Planet(const Planet& x);
	Planet(int id, string name, string desc, int hAM, int hHM, int vAM, int vHM);
	~Planet();
	Planet& operator=(const Planet& x);
	bool operator==(const Planet& x);
	string toString();
	int getID();
	void sethAM(int n);
	void sethHM(int n);
	void setvAM(int n);
	void setvHM(int n);
	int gethAM();
	int gethHM();
	int getvAM();
	int getvHM();

};