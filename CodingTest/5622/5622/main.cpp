#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numOffset[8] = { 3, 3, 3, 3, 3, 4, 3, 4 };

	int firstAsciiNum = int('A') - 1;

	const int size = 16;
	char txt[size]; // 마지막 '\0' 포함
	cin >> txt;

	// 숫자 1이 2초라서 offset 값 2로 지정
	int offset = 3;
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (txt[i] == '\0') break; // 끝에 도달하면 멈춤

		int asciiNum = int(txt[i]);
		int tmp = 0; // 오프셋 인덱스
		int offsetSum = 0;

		while (true)
		{
			offsetSum += numOffset[tmp];

			int asciiRange = firstAsciiNum + offsetSum;
			if (asciiNum <= asciiRange)
			{
				sum += tmp + offset;
				break;
			}
			else tmp++;
		}
	}

	cout << sum;

	return 0;
}