#include "RandomNum.h"
#include <random>

using namespace std;

int RandomNum(int num)
{
	// �յ� ���� ���� ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, num);

	return dis(gen);
}