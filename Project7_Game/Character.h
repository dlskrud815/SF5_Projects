#pragma once

#include <iostream>
#include <vector>

#include "Weapon.h"

using namespace std;

class Character
{
private:
	int hp = 0;
	int level = 0;
	string name;

public:
	static int PlayerlHp;
	static int MonsterHp;

	Character() {}

	virtual void setStatus(int level) {}
	virtual void getWeapon(string weapon) {}
	virtual void attack(Character* ch1, Character* ch2) {}

	void setHp(int hp) { this->hp = hp; }
	
	void setLevel(int level) { this->level = level; }
	void setName(string name) { this->name = name; }

	int getHp() { return this->hp; }
	int getLevel() { return this->level; }
	string getName() { return this->name; }
};

class Player : public Character
{
private:
	int exp = 0;
	vector <Weapon*> weapons;
	
public:
	Player() {}

	void setStatus(int level) override;
	void getWeapon(string weapon) override;
	void attack(Character* ch1, Character* ch2) override;

	int getExp() { return this->exp; }
	vector <Weapon*> getWeaponsList() { return this->weapons; }
	void setExp(int exp) { this->exp = exp; }
};

class Monster : public Character
{
private:
	int atk = 0;
public:
	Monster() {}

	void setAtk(int atk) { this->atk = atk; }
	int getAtk() { return this->atk; }

	void setStatus(int level) override;
	void attack(Character* ch1, Character* ch2) override;
};