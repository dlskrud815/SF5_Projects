#pragma once

#include <iostream>

using namespace std;

class Weapon
{
private:
	int atk = 0; //°ø°Ý·Â
	int atk_num = 0; //°ø°Ý °¡´É È½¼ö
	string name;

public:
	Weapon() {}

	virtual void attack() {}

	int getAtkNum() { return this->atk_num; }
	int getAtk() { return this->atk; }

	void setAtk(int power) { this->atk = power; }
	void setAtkNum(int count) { this->atk_num = count; }
	void setName(string name) { this->name = name; }

	string getName() { return this->name; }
};


class Gun : public Weapon
{
public:
	Gun() {}

	void attack() override
	{
		cout << endl <<"!!! ÃÑ½î±â" << endl << endl;
	}
};


class Sword : public Weapon
{
public:
	Sword() {}

	void attack() override
	{
		cout << endl << "!!! Âî¸£±â" << endl << endl;
	}
};