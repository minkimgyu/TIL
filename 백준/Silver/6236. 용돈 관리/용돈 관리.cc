#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int left = 0;
	int right = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		left = max(left, arr[i]); // 배열의 값 중 가장 큰 값을 사용해야함
		right += arr[i]; // 모든 수를 더한 값
	}

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int startMoney = mid;
		int refillCount = 1;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] > startMoney)
			{
				startMoney = mid;
				refillCount++;
			}

			startMoney -= arr[i];
		}

		if (refillCount <= m) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;

	return 0;
}