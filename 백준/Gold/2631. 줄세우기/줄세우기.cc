#include <iostream>
using namespace std;

const int maxSize = 200;
const int offset = 5;
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
		cin >> arr[i];
	}

	fill(dp, dp + maxSize + 1, 1);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int maxResult = 0;
	for (int i = 1; i <= n; i++)
	{
		maxResult = max(maxResult, dp[i]);
	}

	cout << n - maxResult;
	return 0;
}