#include <iostream>
using namespace std;

const int maxSize = 1000 + 5;
int arr[maxSize];
int dp[maxSize];

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

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}

	int result = 0;

	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}