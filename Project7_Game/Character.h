#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Character
{
private:
	int hp;
	int level;
	vector <string> weapons;

public:
	Character(int hp, int level)
	{
		this->hp = hp;
		this->level = level;
	}

	void getWeapon() {}
	void attack() {}
};