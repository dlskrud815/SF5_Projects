//작성자: 이나경
// 2024.05.22.
//
// - 프로젝트 6. 계산기 만들기 -
// 1. 클래스 상속, 정적 멤버, 업 캐스팅, 가상 함수를 사용하여 다음과 같이
// 간단한 사칙연산을 수행하는 계산기 만들기
// • Y : 도출된 결과를 이용한 후속 계산
// • AC : 이전 기록 초기화
// • EXIT : 종료

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Calculator
{
public:
	Calculator() {}
	virtual void calculate(float num1, float num2) {};
	float getResult() { return this->result; }
	static float tempResult;

protected:
	void setResult(float result) { this->result = result; }

private:
	float num1 = 0;
	float num2 = 0;
	float result = 0;
};

class Plus : public Calculator
{
public:
	void calculate(float num1, float num2) override
	{
		setResult(num1 + num2);
	}
};


class Minus : public Calculator
{
public:
	void calculate(float num1, float num2) override
	{
		setResult(num1 - num2);
	}
};

class Multiply : public Calculator
{
public:
	void calculate(float num1, float num2) override
	{
		setResult(num1 * num2);
	}
};

class Divide : public Calculator
{
public:
	void calculate(float num1, float num2) override
	{
		if (num2 != 0)
			setResult(num1 / num2);
		else
			cout << "* 에러: 0으로 나누기 불가" << endl;
	}
};

float Calculator::tempResult = 0;
Calculator* findOperClass(char oper);
float checkNum(string input);
float checkNum2(string input, char oper);
char checkOper(char oper);

int main()
{
	float num1, num2;
	char oper;
	string input, answer;
	Calculator* cal;

	cout << "* 계산기 *" << endl;

	cout << endl << "숫자를 입력해주세요 : ";
	cin >> input;
	num1 = checkNum(input);

	cout << endl << "연산자를 입력해주세요 : ";
	cin >> oper;
	oper = checkOper(oper);

	cout << endl << "숫자를 입력해주세요 : ";
	cin >> input;
	num2 = checkNum2(input, oper);

	cal = findOperClass(oper);

	if (cal) {
		cal->calculate(num1, num2);
	}
	else {
		cout << "* 에러: Calculator 클래스 nullptr" << endl;
		return 0;
	}

	Calculator::tempResult = cal->getResult();

	cout << endl << "-----------------------------" << endl
		<< "결과 : " << Calculator::tempResult << endl
		<< "-----------------------------" << endl;

	while (1)
	{
		cout << endl << "연산을 계속 진행하시겠습니까? (Y: 계속, AC: 초기화, EXIT: 종료) ";
		cin >> answer;

		while (1)
		{
			if (answer == "Y" || answer == "AC" || answer == "EXIT") break;
			else
			{
				cout << "* 잘못된 입력입니다." << endl << endl
					<< "[재입력]" << endl
					<< "연산을 계속 진행하시겠습니까? (Y: 계속, AC: 초기화, EXIT: 종료) ";
				cin >> answer;
			}
		}

		if (answer == "Y")
		{
			cout << endl << "연산자를 입력해주세요 : ";
			cin >> oper;
			oper = checkOper(oper);

			cout << endl << "숫자를 입력해주세요 : ";
			cin >> input;
			num2 = checkNum2(input, oper);

			cal = findOperClass(oper);
			num1 = Calculator::tempResult;
		}
		else if (answer == "AC")
		{
			cout << endl << "숫자를 입력해주세요 : ";
			cin >> input;
			num1 = checkNum(input);

			cout << endl << "연산자를 입력해주세요 : ";
			cin >> oper;
			oper = checkOper(oper);

			cout << endl << "숫자를 입력해주세요 : ";
			cin >> input;
			num2 = checkNum2(input, oper);

			cal = findOperClass(oper);
		}
		else if (answer == "EXIT")
		{
			cout << endl <<"연산을 종료합니다." << endl;
			return 0;
		}

		cal->calculate(num1, num2);
		Calculator::tempResult = cal->getResult();

		cout << endl << "-----------------------------" << endl
			<< "결과 : " << cal->getResult() << endl
			<< "-----------------------------" << endl;
	}
	return 0;
}

Calculator* findOperClass(char oper)
{
	Calculator* cal;

	if (oper == '+')
	{
		cal = new Plus();
	}
	else if (oper == '-')
	{
		cal = new Minus();
	}
	else if (oper == '*')
	{
		cal = new Multiply();
	}
	else if (oper == '/')
	{
		cal = new Divide();
	}
	else
	{
		return nullptr;
	}

	return cal;
}

float checkNum(string input)
{
	vector <string> x;
	string str;
	bool check;

	while (1)
	{
		x.clear();
		check = false;
		stringstream ss(input);
		
		for (char ch : input)
		{
			if (isdigit(ch) == 0) //숫자가 아님
			{
				check = true;
				break;
			}
		}

		if (!check) //정수 확인
		{
			break;
		}
		else //입력 값이 숫자가 아님
		{
			check = false;

			while (getline(ss, str, '.'))
			{
				x.push_back(str);
			}

			for (string xx : x)
			{
				for (char xxx : xx)
				{
					if (isdigit(xxx) == 0) //숫자가 아님
					{
						check = true;
						break;
					}
				}
				if (check == true) break;
			}
		}

		if (!check) //실수 확인
		{
			break;
		}
		else
		{
			cout << endl << "[재입력]" << endl << "숫자를 입력해주세요 : ";
			cin >> input;
		}
	}

	return stof(input);
}

float checkNum2(string input, char oper)
{
	float num2 = checkNum(input);

	while (1)
	{
		if (oper == '/' && num2 == 0)
		{
			cout << "* 0으로 나눌 수 없습니다." << endl
				<< endl << "[재입력]" << endl
				<< "숫자를 입력해주세요 : ";
			cin >> num2;
		}
		else break;
	}

	return num2;
}

char checkOper(char oper)
{
	vector <char> op = { '+', '-', '*', '/' };
	bool check;

	while (1)
	{
		check = false;
		//사칙연산 중 일치하는 게 있으면
		for (char o : op)
		{
			if (oper == o)
			{
				check = true;
				break;
			}
		}
		if (check) break;
		else
		{
			cout << "* 사칙연산만 가능합니다" << endl << endl 
				<< "[재입력]" << endl << "연산자를 입력해주세요 : ";
			cin >> oper;
		}
	}

	return oper;
}