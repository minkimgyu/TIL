#include <iostream>
using namespace std;

const int maxSize = 100 + 5;
int arr[maxSize];

const int maxValue = 10000 + 5;
int dp[maxValue];

int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= k; i++) dp[i] = maxValue;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 0;

	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + arr[j] >= maxValue) continue;

			dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
		}
	}

	if (dp[k] == maxValue) cout << -1;
	else cout << dp[k];
	return 0;
}