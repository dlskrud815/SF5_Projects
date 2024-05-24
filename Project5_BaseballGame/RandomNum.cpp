#include "RandomNum.h"

vector <int> GetRandomNum(int num1, int num2)
{
	vector <int> v_random;
	int randomNum;

	// 균등 분포 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, num1);

	// num 개 추출할 때까지 난수 생성 반복
	while (v_random.size() < num2)
	{
		randomNum = dis(gen);

		// 중복 확인 후 추가
		if (find(v_random.begin(), v_random.end(), randomNum) == v_random.end())
		{
			v_random.push_back(randomNum);
		}
	}

	return v_random;
}
