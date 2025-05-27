#include <iostream>
using namespace std;

const int maxSize = 20 + 5;
const int maxHp = 100 + 5;

int dp[maxSize][maxHp];
pair<int, int> arr[maxSize];

int dfs(int n, int k)
{
	if (n == 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];

	if (k - arr[n - 1].first <= 0)
	{
		dp[n][k] = max(dp[n][k], dfs(n - 1, k));
	}
	else
	{
		dp[n][k] = max(dp[n][k], max(dfs(n - 1, k - arr[n - 1].first) + arr[n - 1].second, dfs(n - 1, k)));
	}

	return dp[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxHp; j++)
		{
			dp[i][j] = -1;
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].second;
	}

	cout << dfs(n, 100);
	return 0;
}