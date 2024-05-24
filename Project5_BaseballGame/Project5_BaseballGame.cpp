// 작성자: 이나경
// 2024.05.22.
//
// - 프로젝트 5. 야구 게임 -
// 1) 사용자는 1부터 9까지 중 3개의 숫자를 뽑아 컴퓨터가 랜덤으로 뽑은 숫자 3개와 비교(중복 x)
//    숫자의 자리와 값이 모두 같으면 strike
//    자리는 다르지만 3개의 숫자 중 포함 되어 있으면 ball

#include <iostream>
#include "RandomNum.h"

using namespace std;

int main()
{
	int count, num1, num2, num3, strike, ball;
	vector <int> v_random, v_input;

	cout << "* 야구 게임 " << endl << endl;

	//1~9까지 3개 난수 생성
	v_random = GetRandomNum(9, 3);

	for (int v : v_random)
	{
		cout << v << " ";
	}

	cout << endl;
	count = 0;
	while (1)
	{
		count++;

		strike = 0, ball = 0;
		v_input.clear();

		cout << "1 ~ 9 사이의 숫자 3개를 입력 하시오 (이외의 숫자: 종료)" << endl;
		cin >> num1 >> num2 >> num3;

		while (1)
		{
			if (num1 == num2 || num2 == num3 || num1 == num3)
			{
				cout << "* 숫자 중복" << endl << endl << "[재입력]" << endl 
					<< "1 ~ 9 사이의 숫자 3개를 입력 하시오 (이외의 숫자: 종료)" << endl;
				cin >> num1 >> num2 >> num3;
			}
			else break;
		}

		v_input.push_back(num1);
		v_input.push_back(num2);
		v_input.push_back(num3);

		//이외 숫자 입력 시 종료
		if (num1 > 9 || num1 < 1 || num2 > 9 || num2 < 1 || num3 > 9 || num3 < 1)
		{
			break;
		}

		for (int i = 0; i < v_random.size(); i++)
		{
			if (v_random[i] == v_input[i])
			{
				// 같은 위치에 같은 값 = 스트라이크
				strike++;
			}
			else
			{
				// 다른 위치에 같은 값 = 볼
				for (int j = 0; j < v_input.size(); j++)
				{
					if (v_random[i] == v_input[j])
					{
						ball++;
					}
				}
			}
		}

		cout << "Strike : " << strike << "\tBall : " << ball << endl << endl;

		if (strike >= 3)
		{
			cout << count << "번 만에 맞혔습니다." << endl;
			break;
		}
	}

	cout << endl << "게임을 종료하였습니다." << endl;

	return 0;
}