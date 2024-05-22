// 작성자: 이나경
// 2024.05.22.
//
// - 프로젝트 3. 랜덤 숫자 맞히기 -
// 1) 컴퓨터가 1~25까지의 수 중 랜덤으로 6개의 수 지정 (중복 x)
// 2) 사용자도 1~25까지의 수 중 원하는 숫자 6개 입력(중복 x)
// 3) 두 배열을 비교해서 몇 등인지 출력하기!
//    3-1) 한 개도 맞추지 못하면 7등, 1개만 맞추면 6등, 2개 맞추면 5등...
//    3-2) 6개를 모두 맞추면 1등

#include <iostream>
#include "Lotto.h"

using namespace std;

int main()
{
	int num1 = 25, num2 = 6, i = 0, input, errType = 0;
	vector <int> v_lotto, v_input;
	// 1~25 랜덤 6개
	v_lotto = GetLottoNum(num1, num2);

	cout << "숫자는 1 ~ 25까지의 숫자만 입력할 수 있습니다." << endl << endl;

	while (i < 6)
	{
		cout << i+1 << "번째 번호를 입력하세요: ";
		cin >> input;

		if (input < 0 || input > num1)
		{
			errType = 1;
		}
		else
		{
			for (int in : v_input)
			{
				if (in == input)
				{
					errType = 2;
				}
			}
		}

		switch (errType)
		{
		case 0:
			v_input.push_back(input);
			i++;
			break;
		case 1:
			cout << "잘못된 숫자입니다. 다시 입력해주세요." << endl;
			break;
		case 2:
			cout << "이미 입력된 숫자입니다." << endl;
			break;
		}

		errType = 0;
	}

	cout << "------------------------------------------------------" << endl << endl
		<< "당첨번호 공개!" << endl;
	
	for (int in : v_lotto)
	{
		cout << in << " ";
	}

	cout << endl << endl << "1 ~ 7등까지 결과가 나올 수 있습니다." << endl
		<< "결과 : " << WinningLotto(v_input, v_lotto) << endl;

	return 0;
}