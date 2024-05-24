#include "Character.h"

#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

void Player::getWeapon(string weapon)
{
	string line, str;
	vector <vector<string>> data;
	vector <string> temp;
	bool check = false;

	ifstream weaponData("WeaponData.txt");

	while (getline(weaponData, line))
	{
		stringstream ss;
		ss.str(line);

		temp.clear();
		while (ss >> str)
		{
			temp.push_back(str);
		}
		data.push_back(temp);
	}

	weaponData.close();

	int i = 0;
	for (vector<string> v : data)
	{
		if (v[1] == weapon)
		{
			check = true;
			break;
		}
		i++;
	}

	//파일 데이터와 확인
	if (check)
	{
		vector <Weapon*> v_w;
		
		bool same = false;

		if (data[i][0] == "칼")
		{
			 Weapon* w = new Sword();
			 w->setAtk(stoi(data[i][2]));
			 w->setAtkNum(stoi(data[i][3]));
			 w->setName(data[i][1]);
			 v_w.push_back(w);
		}
		else if (data[i][0] == "총")
		{
			Weapon* w = new Gun();
			w->setAtk(stoi(data[i][2]));
			w->setAtkNum(stoi(data[i][3]));
			w->setName(data[i][1]);
			v_w.push_back(w);
		}

		if (this->weapons.size() <= 0)
		{
			this->weapons.push_back(v_w[0]);
			cout << "! " << v_w[0]->getName()
				<< "을 얻었습니다. " << endl << endl;
		}
		else
		{
			for (Weapon* ww : this->weapons)
			{
				if (ww->getName() == v_w[0]->getName())
				{
					same = true;
					break;
				}
			}

			if (same)
			{
				cout << endl << "* 이미 " << v_w[0]->getName()
					<< "을 소유하고 있습니다. 사용가능 횟수를 추가합니다." << endl;

				//사용 횟수 추가하기!
				for (Weapon* ww : this->weapons)
				{
					if (ww->getName() == v_w[0]->getName())
					{
						ww->setAtkNum(ww->getAtkNum() + v_w[0]->getAtkNum());
						cout << v_w[0]->getName() << "의 사용가능 횟수: " << ww->getAtkNum() << endl;
						break;
					}
				}
			}
			else
			{
				this->weapons.push_back(v_w[0]);
				cout << "* " << data[i][1]
					<< "을 얻었습니다. " << endl;
			}
		}
		v_w.clear();
	}
}
 
void Player::setStatus(int level) 
{
	this->setLevel(level);

	//체력=기본 체력+(레벨−1)×레벨당 증가 체력
	int hp = 100 + (level - 1) * 15;
	this->setHp(hp);
}

void Monster::setStatus(int level)
{
	int hp = 50 + (level - 1) * 30;
	int atk = 20 + (level - 1) * 10;

	this->setLevel(level);
	this->setHp(hp);
	this->setAtk(atk);
}

void Player::attack(Character* ch1, Character* ch2)
{
	//무기 고르기
	cout << endl << "[현재 소유한 무기]" << endl << endl;
	int i = 0, choice;

	for (Weapon* list : this->getWeaponsList())
	{
		cout << i + 1 << ". " << list->getName() << endl << "- 공격력: " << list->getAtk()
			<< " 사용 가능 횟수: " << list->getAtkNum() << endl;
		i++;
	}

	cout << endl << "어떤 무기를 선택하시겠습니까? (무기 번호를 입력하세요.) ";
	cin >> choice;

	while ((choice - 1) > this->getWeaponsList().size() || (choice - 1) < 0)
	{
		cout << "* 존재하지 않는 번호입니다." << endl << endl << "[재입력]"
			<< endl << "어떤 무기를 선택하시겠습니까? (무기 번호를 입력하세요.) ";
		cin >> choice;
	}

	this->getWeaponsList()[choice - 1]->attack();

	// 몬스터 체력 소모
	ch2->setHp(ch2->getHp() - this->getWeaponsList()[choice - 1]->getAtk());
	
	Sleep(500);

	if (ch2->getHp() <= 0)
	{
		cout << endl << ch2->getName() << " 잔여 HP: 0" << endl;
	}
	else
	{
		cout << endl << ch2->getName() << " 잔여 HP: " << ch2->getHp() << endl;
	}
	
	// 무기 사용 횟수 소모
	if (this->getWeaponsList()[choice - 1]->getAtk() != 0)
	{
		this->getWeaponsList()[choice - 1]->setAtkNum(this->getWeaponsList()[choice - 1]->getAtkNum() - 1);
	}
}

void Monster::attack(Character* ch1, Character* ch2) //플레이어명으로 처리
{
	Monster* m = (Monster*)ch2;
	ch1->setHp(ch1->getHp() - m->getAtk());

	Sleep(500);

	if (ch1->getHp() <= 0)
	{
		cout << endl << ch2->getName() << "의 공격을 받았습니다. " << endl << endl
			<< "플레이어 잔여 HP: 0" << endl;
	}
	else
	{
		cout << endl << ch2->getName() << "의 공격을 받았습니다. " << endl << endl
			<< "플레이어 잔여 HP: " << ch1->getHp() << endl;
	}
}