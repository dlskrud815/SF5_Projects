// 작성자: 이나경
// 2024.05.22.
// 
// - 프로젝트 1. 배스킨라빈스 31 게임 -
// 서로 최소 1개에서 최대 3개의 연속된 숫자를 말하고
// 31이라는 숫자를 말하는 사람이 지는 게임.
// 
// 1) 사용자는 본인이 입력한 숫자만큼.
// 2) 컴퓨터는 랜덤 숫자만큼.
// 3) 단 사용자, 컴퓨터 모두 1~3사이의 개수만 가능

#include <iostream>
#include "RandomNum.h"

using namespace std;

int main()
{
	int input, output = 0, computerNum;

	cout << "* 배스킨라빈스 31 게임 " << endl << endl
		<< "- 게임을 시작합니다! -" << endl;

	while (1)
	{
		//사용자 입력부
		cout << endl << "개수를 입력하세요: ";
		cin >> input;

		while (1)
		{
			if (input > 3 || input < 1)
			{
				cout << endl << "* 1~3 사이의 수를 입력하세요." << endl
					<< "[재입력]" << endl << "개수를 입력하세요: ";
				cin >> input;
			}
			else break;
		}

		cout << endl << "사용자가 부른 숫자!" << endl;
		for (int i = 0; i < input; i++)
		{
			cout << ++output << endl;

			if (output >= 31)
			{
				cout << endl << "게임종료! 컴퓨터의 승리입니다." << endl;
				return 0;
			}
		}

		//1~3 중 랜덤 숫자 생성
		computerNum = RandomNum(3);

		cout << endl << "컴퓨터가 부른 숫자!" << endl;
		for (int i = 0; i < computerNum; i++)
		{
			cout << ++output << endl;

			if (output >= 31)
			{
				cout << endl << "게임종료! 사용자의 승리입니다." << endl;
				return 0;
			}
		}
	}
}
