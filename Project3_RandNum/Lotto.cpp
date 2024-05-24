#include "Lotto.h"
#include <iostream>

vector <int> GetLottoNum(int num1, int num2)
{
	vector <int> v_lotto;
	int randomNum;

	// 균등 분포 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, num1);

	// 로또 번호 num 개 추출할 때까지 난수 생성 반복
	while (v_lotto.size() < num2)
	{
		randomNum = dis(gen);

		if (find(v_lotto.begin(), v_lotto.end(), randomNum) == v_lotto.end())
		{
			v_lotto.push_back(randomNum);
		}
	}

	return v_lotto;
}

int WinningLotto(vector<int> v_input, vector<int> v_lotto)
{
	int rank = 0, check = 0;

	for (int lotto : v_lotto)
	{
		for (int input : v_input)
		{
			if (lotto == input)
			{
				check++;
				break;
			}
		}
	}

	switch (check)
	{
	case 0:
		rank = 7;
		break;
	case 1:
		rank = 6;
		break;
	case 2:
		rank = 5;
		break;
	case 3:
		rank = 4;
		break;
	case 4:
		rank = 3;
		break;
	case 5:
		rank = 2;
		break;
	case 6:
		rank = 1;
		break;
	}

	return rank;
}