#include <iostream>
using namespace std;

const int maxSize = 100 + 5;
pair<int, int> arr[maxSize];

int dp[100 + 5][10000 + 5]; // 개수, 시간

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t;
	cin >> n >> t;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second; 
		// 시간, 배점
		// w, p
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (arr[i].first > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], arr[i].second + dp[i - 1][j - arr[i].first]);
			}
		}
	}

	cout << dp[n][t];
	return 0;
}