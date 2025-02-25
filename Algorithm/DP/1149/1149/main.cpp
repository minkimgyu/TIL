#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000 + 5;
int cost[4][maxSize];
int dp[4][maxSize]; // 경우의 수, cost 인덱스

const int maxValue = 1000000 + 5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[1][i] >> cost[2][i] >> cost[3][i];

		dp[1][i] = maxValue;
		dp[2][i] = maxValue;
		dp[3][i] = maxValue;
	}

	dp[1][1] = cost[1][1];
	dp[2][1] = cost[2][1];
	dp[3][1] = cost[3][1];

	for (int i = 2; i <= n; i++)
	{
		dp[1][i] = min(dp[1][i], min(dp[2][i - 1] + cost[1][i], dp[3][i - 1] + cost[1][i]));
		dp[2][i] = min(dp[2][i], min(dp[1][i - 1] + cost[2][i], dp[3][i - 1] + cost[2][i]));
		dp[3][i] = min(dp[3][i], min(dp[1][i - 1] + cost[3][i], dp[2][i - 1] + cost[3][i]));
	}

	cout << min({ dp[1][n], dp[2][n], dp[3][n] });
	return 0;
}