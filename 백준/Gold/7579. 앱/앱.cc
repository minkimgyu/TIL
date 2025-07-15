#include <iostream>
using namespace std;

const int maxCount = 100 + 5;
const int maxCost = 100 * 100 + 5;
int dp[maxCount][maxCost];

pair<int, int> apps[maxCount];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int totalCost = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> apps[i].first;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> apps[i].second;
		totalCost += apps[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= totalCost; j++)
		{
			if (j - apps[i].second >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - apps[i].second] + apps[i].first);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 0; i <= totalCost; i++)
	{
		if (dp[n][i] >= m)
		{
			cout << i;
			break;
		}
	}

	return 0;
}