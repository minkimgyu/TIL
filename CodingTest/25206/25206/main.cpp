#include <iostream>
#include <cmath>
using namespace std;

// score * 4.5f; --> 기억하기
// 소수점 4번째 자리에서 잘라야함
// 
// #include <cmath> 사용하고
// ceil(problem * 10) / 10 --> 이런 식으로 계산해줘야함

int main()
{
	int n = 20;
	float totalScore = 0;
	float totalGrade = 0;

	for (int i = 0; i < n; i++)
	{
		char arr[51];
		float score;
		char grade[3];

		cin >> arr >> score >> grade;

		if (grade[0] == 'A' && grade[1] == '+') 
		{
			totalScore += score;
			totalGrade += score * 4.5f;
		}
		else if (grade[0] == 'A' && grade[1] == '0')
		{
			totalScore += score;
			totalGrade += score * 4.0f;
		}
		else if (grade[0] == 'B' && grade[1] == '+')
		{
			totalScore += score;
			totalGrade += score * 3.5f;
		}
		else if (grade[0] == 'B' && grade[1] == '0')
		{
			totalScore += score;
			totalGrade += score * 3.0f;
		}
		else if (grade[0] == 'C' && grade[1] == '+')
		{
			totalScore += score;
			totalGrade += score * 2.5f;
		}
		else if (grade[0] == 'C' && grade[1] == '0')
		{
			totalScore += score;
			totalGrade += score * 2.0f;

		}
		else if (grade[0] == 'D' && grade[1] == '+')
		{
			totalScore += score;
			totalGrade += score * 1.5f;
		}
		else if (grade[0] == 'D' && grade[1] == '0')
		{
			totalScore += score;
			totalGrade += score * 1.0f;
		}
		else if (grade[0] == 'F')
		{
			totalScore += score;
			totalGrade += score * 0;
		}
		else if (grade[0] == 'P')
		{
			// 아무 것도 하지 않음
		}
	}

	float anw = totalGrade / totalScore;
	anw = ceil(anw * 10000.0f) / 10000.0f;

	cout << anw;

	return 0;
}