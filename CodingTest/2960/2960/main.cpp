#include <iostream>
using namespace std;

// 알고리즘 적혀있는 방식대로 풀이하면 되는 문제
// 값을 빼는 경우 0을 원래 값 대신해서 넣어준다.
// 만약 0인 경우 continue 후 다음 multiply 값을 곱해서 탐색해준다.


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	int arr[1000] { -1 };

	for (int i = 0; i < n - 1; i++)
	{
		arr[i] = i + 2;
	}

	int cnt = 0;
	while (1)
	{
		int index = -1;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] != 0)
			{
				index = i;
				break;
			}
		}

		if (index == -1) break;

		int multiply = 1;
		int findValue = arr[index];
		while (1)
		{
			int value = findValue * multiply;
			if (value - 2 > n - 1) break;

			multiply++;
			if (arr[value - 2] == 0) continue;

			cnt++;
			if (cnt == k)
			{
				cout << arr[value - 2];
				return 0;
			}

			arr[value - 2] = 0;
		}
	}

	return 0;
}