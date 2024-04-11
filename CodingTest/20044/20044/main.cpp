#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

// 문제 설명은 좀 복잡하지만
// 간단하게 풀이하자면 가장 큰 값과 작은 값을 더하고
// 다음에는 2번째로 큰 값과 작은 값을 더해간다.
// 
// 이를 계속 진행하면서
// 가장 작은 값을 구하면 되는 문제이다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[2 * n];
	for (int i = 0; i < n * 2; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + 2 * n, compare);

	int min;

	for (int i = 0; i < n; i++)
	{
		int sum = arr[i] + arr[2 * n - 1 - i];
		if (i == 0) min = sum;
		else
		{
			if (min > sum) min = sum;
		}
	}

	cout << min;

	return 0;
}