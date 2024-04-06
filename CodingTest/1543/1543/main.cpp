#include <iostream>
using namespace std;

// 그리디적으로 접근한다면 가장 첫번째부터 겹치는 문자열을 확인해야할 필요가 있음
// 인덱싱이 어려운 문제
// 인덱스마다 찾는 문자의 길이만큼 확인하는 작업이 필요함
// 
// abababc
// ababc
// --> 이런 반례도 존재하기 때문에 그런 것임
//

int main()
{
	const int arrSize = 2501;
	char* arr = new char[arrSize];

	const int findSize = 51;
	char* findArr = new char[findSize];

	cin.getline(arr, arrSize);
	cin.getline(findArr, findSize);

	int arrCnt = 0;
	while (1)
	{
		if (arr[arrCnt] == '\0') break;
		arrCnt++;
	}

	int cnt = 0;
	int index = 0;
	while (1)
	{
		if (index > arrCnt || arr[index] == '\0') break;

		int tmpIndex = 0;
		while (1)
		{
			if (findArr[tmpIndex] == '\0')
			{
				cnt++; // 찾음
				index += tmpIndex - 1;
				break;
			}

			if (arr[index + tmpIndex] == '\0')
			{
				break; // arr의 끝에 도달함
			}

			if (arr[index + tmpIndex] != findArr[tmpIndex]) break;

			tmpIndex++;
		}

		index++;
	}

	cout << cnt;

	return 0;
}