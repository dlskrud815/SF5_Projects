#include "RandomNum.h"

vector <int> GetRandomNum(int num1, int num2)
{
	vector <int> v_random;
	int randomNum;

	// �յ� ���� ���� ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, num1);

	// num �� ������ ������ ���� ���� �ݺ�
	while (v_random.size() < num2)
	{
		randomNum = dis(gen);

		// �ߺ� Ȯ�� �� �߰�
		if (find(v_random.begin(), v_random.end(), randomNum) == v_random.end())
		{
			v_random.push_back(randomNum);
		}
	}

	return v_random;
}
