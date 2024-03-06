#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numToGetRemain = 42;

	const int cnt = 10;
	int arr[cnt];

	for (int i = 0; i < cnt; i++)
	{
		int input;
		cin >> input;

		arr[i] = input % numToGetRemain;
	}

	int count = 0;

	for (int i = 0; i < cnt; i++)
	{
		int tmp = arr[i];

		if(i + 1 == cnt) count++; // i가 마지막 인덱스인 경우, 카운트를 올려줌

		for (int j = i + 1; j < cnt; j++)
		{
			if (tmp == arr[j]) break;

			if (j == cnt - 1) count++; // 마지막까지 도달한 경우
		}
	}

	cout << count;

	return 0;
}