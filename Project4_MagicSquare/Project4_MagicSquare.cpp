// 작성자: 이나경
// 2024.05.22.
//
// - 프로젝트 4. 마방진 만들기 -
// 마방진이란? 1에서 n제곱까지의 수를 정사각형으로 배열해 가로, 세로, 대각의 합계가 모두 같도록 만든 것
// 사용자로부터 홀수 n을 입력 받아 n*n의 마방진 만들기

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int num, sum, sumCheck, row, col, n;
	vector <vector<int>> MagicSquare;
	vector <int> MagicSquare_rows;

	cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요: ";
	cin >> num;

	while (num%2 == 0)
	{
		cout << endl << "* 홀수를 입력해주세요." << endl << endl
			<< "[재입력]" << endl
			<< "마방진의 행 혹은 열의 수를 자연수로 입력해주세요: ";
		cin >> num;
	}

	//마방진 전체 합
	sum = ((num * num) * ((num * num) + 1)) / 2;

	//마방진 벡터 크기 지정
	MagicSquare_rows.resize(num, 0);
	MagicSquare.resize(num, MagicSquare_rows);

	row = 0, col = num / 2, n = 1;

	while (1)
	{
		sumCheck = 0;

		//45
		for (int i = 0; i < MagicSquare.size(); i++)
		{
			for (int j = 0; j < MagicSquare_rows.size(); j++)
			{
				sumCheck += MagicSquare[i][j];
			}
		}

		if (sumCheck >= sum) break;

		MagicSquare[row][col] = n++;

		if (row == 0 && col == MagicSquare.size() - 1)
		{
			row++;
		}
		else
		{
			if (--row < 0)
			{
				row = num - 1;
			}
			if (++col > num - 1)
			{
				col = 0;
			}
			if (MagicSquare[row][col] != 0)
			{
				col--;
				row += 2;
			}
		}
	}

	//마방진 벡터 출력
	for (int i = 0; i < MagicSquare.size(); i++)
	{
		for (int j = 0; j < MagicSquare_rows.size(); j++)
		{
			cout << MagicSquare[i][j] << "\t";
		}
		cout << endl;
	}
	
	return 0;
}