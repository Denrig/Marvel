#pragma once
#include "Fight.h"
#include <iostream>
#include <Windows.h>

using namespace std;

class UI {
	private:
		Fight f = Fight();
public:
	
	UI();
	~UI();
	void startUP();
	void ClearScreen();
};