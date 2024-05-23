#pragma once

#include <iostream>

using namespace std;

class Weapon
{
private:
	int atk = 0; //°ø°Ý·Â
	int atk_num = 0; //°ø°Ý °¡´É È½¼ö

public:
	virtual void attack() {}

	void setAtk(int power) { this->atk = power; }
	void setAtkNum(int count) { this->atk_num = count; }
};


class Gun : public Weapon
{
public:
	Gun()
	{
		this->setAtk(10);
		this->setAtkNum(1);
	}

	void attack() override
	{
		cout << "ÃÑ½î±â" << endl;
	}
};


class Sword : public Weapon
{
public:
	Sword()
	{
		this->setAtk(5);
		this->setAtkNum(3);
	}

	void attack() override
	{
		cout << "Âî¸£±â" << endl;
	}
};