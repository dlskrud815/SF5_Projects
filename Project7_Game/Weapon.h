#pragma once

#include <iostream>

using namespace std;

class Weapon
{
private:
	int atk = 0; //���ݷ�
	int atk_num = 0; //���� ���� Ƚ��

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
		cout << "�ѽ��" << endl;
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
		cout << "���" << endl;
	}
};