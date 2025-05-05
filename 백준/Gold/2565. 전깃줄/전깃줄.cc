#include <iostream>
using namespace std;

const int offset = 5;
const int maxSize = 500;
int arr[maxSize + offset];
int dp[maxSize + offset];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int index, value;
		cin >> index >> value;

		arr[index] = value;
	}

	fill(dp, dp + maxSize, 1);

	for (int i = 1; i <= maxSize; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] != 0 && arr[i] > arr[j]) // 0이 아니고 arr[i]가 더 큰 경우
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// for 문을 돌지 않을 수도 있기 때문에 나중에 검사
	int maxResult = 0;
	for (int i = 1; i <= maxSize; i++)
	{
		maxResult = max(maxResult, dp[i]);
	}

	cout << n - maxResult;
	return 0;
}