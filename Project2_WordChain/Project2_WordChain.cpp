// 작성자: 이나경
// 2024.05.22.
// 
// - 프로젝트 2. 타임어택 끝말잇기 게임 -
// 1) 제한 시간 30초 동안 플레이어는 끝말잇기 규칙에 따라 단어를 입력
// 2) 제한 시간이 종료되면 게임을 종료 시키고, 입력한 단어의 개수를 출력
// 3) 단, 한번 입력된 단어는 입력하지 못하게 하기

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
	int errType = 0;
	string word;
	char last = ' ';
	vector <string> wordChain = { "airplane" };

	cout << "* 타임어택 끝말잇기 게임" << endl << endl
		<< "- 제한시간은 30초 입니다. -" << endl;

	clock_t startTime = clock();
	while (1)
	{
		cout << endl;
		for (int i = 0; i < wordChain.size(); i++)
		{
			cout << wordChain[i];

			if (i != wordChain.size() - 1)
			{
				cout << " -> ";
			}
			else
			{
				//마지막 알파벳
				last = wordChain[i][wordChain[i].length() - 1];
			}
		}

		cout << endl << "다음 단어를 입력하세요 : ";
		cin >> word;

		while (1)
		{
			if (word[0] != last)
			{
				errType = 1;
			}
			else
			{
				for (int i = 0; i < wordChain.size(); i++)
				{
					if (word == wordChain[i])
					{
						errType = 2;
						break;
					}
				}
			}

			switch (errType)
			{
			case 1:
				cout << endl << "* 마지막 알파벳 " << last << "(으)로 시작하는 단어를 입력해주세요." << endl << endl;
				break;
			case 2:
				cout << endl << "* 중복된 단어입니다." << endl << endl;
				break;
			}

			if (!errType) break;
			else
			{
				errType = 0;
				cout << "[재입력]" << endl << "다음 단어를 입력하세요 : ";
				cin >> word;
			}
		}

		clock_t endTime = clock();

		if ((endTime - startTime) / CLOCKS_PER_SEC > 30)
		{
			cout << "타임 오버!" << endl;
			break;
		}

		wordChain.push_back(word);
	}

	cout << endl << "게임 종료!" << endl
		<< "총 입력한 단어 개수 : " << wordChain.size() << endl;
}
