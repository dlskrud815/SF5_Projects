//작성자: 이나경
// 2024.05.23.
//
// - 프로젝트 7. 게임 만들기 -
// 1. 캐릭터, 무기, 칼, 총 클래스를 만들어준다.
// 2. 캐릭터 클래스
//    - 필드: ‘hp’, ‘level’, ‘무기들’
//    - 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는 무기들만 사용해서 
//      공격할 수 있으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼 감소한다.)
// 3. 무기 클래스
//    - 필드 : 공격력, 공격 가능 횟수
//    - 메소드 : 공격하기
// 4. 총 & 칼 클래스(무기 클래스를 상속 받는 클래스)
//    - 칼 : 공격력 - 5, 공격가능횟수 - 3, 공격하기 - "찌르기" 출력
//    - 총 : 공격력 - 10, 공격가능횟수 - 1, 공격하기 - "총쏘기" 출력
// 5. 파일 분리하기

#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <sstream>

#include "Character.h"

using namespace std;

void Loading(int sec)
{
	int i = 0;
	while (i < sec)
	{
		Sleep(500);
		cout << ". ";
		i++;
	}
	cout << endl << endl;
};

int Character::MonsterHp = 0;
int Character::PlayerlHp = 0;

int main()
{
	while (1)
	{
		Character* player = new Player();

		player->setName("플레이어");
		player->setStatus(1);

		vector<Character*> monsters;
		vector <vector<string>> data;
		vector <string> temp;
		string line1, line2, choice, str;

		//몬스터 불러오기
		ifstream monster("MonsterData.txt");

		while (getline(monster, line1))
		{
			stringstream ss;
			ss.str(line1);

			temp.clear();
			while (ss >> str)
			{
				temp.push_back(str);
			}
			data.push_back(temp);
		}

		monster.close();

		for (vector <string> d : data)
		{
			Character* monster = new Monster();
			monster->setName(d[0]);
			monster->setStatus(stoi(d[1]));

			monsters.push_back(monster);
		}


		//게임 인트로
		ifstream intro("GameIntro.txt");

		cout << endl << "----------------------------------------------------------" << endl << endl;
		Sleep(1500);
		while (getline(intro, line2))
		{
			cout << line2 << endl << endl;
			Sleep(1500);
		}
		cout << "----------------------------------------------------------" << endl << endl;
		intro.close();

		while (1)
		{
			cout << endl << "* 용사가 되어 마을의 평화를 지키겠습니까? (y or n) ";
			cin >> choice;

			if (choice == "y")
			{
				cout << endl << "> 용사, 마을의 평화를 부탁한다." << endl << endl;
				Sleep(500);
				//cout << endl << endl << "! [기본단검]을 얻었다." << endl << endl;
				player->getWeapon("기본단검");
				break;
			}
			else if (choice == "n")
			{
				cout << endl << "> 플레이어, 다시 생각해보길 바란다." << endl << endl
					<< "[재입력]";
			}
			else
			{
				cout << endl << "> 플레이어, 선택은 y, n 둘 중 하나다." << endl << endl
					<< "[재입력]";
			}
		}

		//인트로 끝 게임 시작
		bool life = true;
		int i = 0, monster_num = 0;

		while (life) // 단계별 몬스터
		{
			while (1) // 동단계 몬스터와 싸울 횟수
			{
				Loading(3);
				if (!i)
				{
					if (monsters[monster_num]->getName() == "마왕")
					{
						cout << "----------------------------------------------------------" << endl << endl;
						cout << monsters[monster_num]->getName() << "이다!!!" << endl << endl;
						cout << "----------------------------------------------------------" << endl << endl;
					}
					else
					{
						cout << "----------------------------------------------------------" << endl << endl;
						cout << monsters[monster_num]->getName() << "무리가 길을 막고 있다." << endl << endl;
						cout << "----------------------------------------------------------" << endl << endl;
					}
				}

				Sleep(500);

				Character::PlayerlHp = player->getHp();
				Character::MonsterHp = monsters[monster_num]->getHp();

				while (1) // 몬스터와 전투
				{
					player->attack(player, monsters[monster_num]);

					if (monsters[monster_num]->getHp() <= 0)
					{
						//보상
						switch (monster_num)
						{
						case 0:
							player->getWeapon("롱소드");
							break;
						case 1:
							player->getWeapon("대검");
							break;
						case 2:
							player->getWeapon("권총");
							break;
						case 3:
							player->getWeapon("소총");
							break;
						case 4:
							player->getWeapon("산탄총");
							break;
						}
						break;
					}

					monsters[monster_num]->attack(player, monsters[monster_num]);

					if (player->getHp() <= 0)
					{
						life = false;
						break;
					}
				}

				player->setHp(Character::PlayerlHp);
				monsters[monster_num]->setHp(Character::MonsterHp);

				if (life) // 승리
				{
					player->setLevel(player->getLevel() + 1);
					player->setStatus(player->getLevel());
					cout << endl << "* 플레이어 레벨 업! - 현재 레벨 : " << player->getLevel() << endl;

					if (monster_num != monsters.size()-1) // 마왕이 아닐 때
					{
						if (!i)
						{
							cout << endl << "지나갈 길이 생겼습니다. " << endl << endl;
						}
						cout << "다른 " << monsters[monster_num]->getName() << "와도 싸우시겠습니까? (y or n) ";
						cin >> choice;
						cout << endl;

						if (choice != "y")
						{
							i = 0;
							break;
						}
					}
					else // 마왕일 때
					{
						cout << "> 고맙다, 용사! 이제 마을은 안전하다." << endl
							<< endl << "[게임 종료]" << endl;
						return 0;
					}
				}
				else break; //패배
			}
			
			if (!life) break;
			if (monster_num == monsters.size()) break;
			monster_num++;
		}

		Loading(3);
		cout << "> 용사는 마을을 지키지 못 한 채 사망하였다." << endl << endl;
		Loading(3);
		cout << "[게임 종료]" << endl;
		cout << "> 다시 한 번 도전해보시겠습니까? (y or n) ";
		cin >> choice;

		if (choice != "y")
		{
			return 0;
		}
	}
}