#include <iostream>
#include <algorithm>
using namespace std;

const int maxTime = 1000 + 5;
const int maxMove = 30 + 5;
int dp[maxTime][maxMove];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, w;
	cin >> t >> w;

	for (int i = 1; i <= t; i++)
	{
		int index;
		cin >> index;

		// 이동한 경우
		// 이동하지 않은 경우 나눠야함
		for (int j = 0; j <= w; j++)
		{
			if (index == 1)
			{
				if (j % 2 == 0)
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
				}
				else
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
				}
			}
			else if (index == 2)
			{
				if (j % 2 == 1)
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
				}
				else
				{
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
					dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
				}
			}
		}
	}

	int maxResult = 0;
	for (int i = 0; i <= w; i++)
	{
		maxResult = max(maxResult, dp[t + 1][i]);
	}

	cout << maxResult;
	return 0;
}