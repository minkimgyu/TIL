#include <iostream>
using namespace std;

// 구간, 시간
int dp[101][100001];

int GetMax(int a, int b)
{
	if (a > b) return a;
	else return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	// first는 시간, second는 원
	pair<int, int>* walks = new pair<int, int>[n];
	pair<int, int>* bikes = new pair<int, int>[n];

	for (int i = 1; i <= n; i++)
	{
		cin >> walks[i].first >> walks[i].second >> bikes[i].first >> bikes[i].second;
	}

	dp[1][walks[1].first] = walks[1].second;
	dp[1][bikes[1].first] = GetMax(dp[1][bikes[1].first], bikes[1].second);


	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (dp[i - 1][j] == 0) continue;

			if (j + walks[i].first <= k)
			{
				dp[i][j + walks[i].first] = 
					GetMax(dp[i][j + walks[i].first], dp[i - 1][j] + walks[i].second);
			}

			if (j + bikes[i].first <= k)
			{
				dp[i][j + bikes[i].first] =
					GetMax(dp[i][j + bikes[i].first], dp[i - 1][j] + bikes[i].second);
			}
		}
	}

	int result = 0;
	for (int j = 1; j <= k; j++)
	{
		result = GetMax(result, dp[n][j]);
	}

	cout << result;
	return 0;
}