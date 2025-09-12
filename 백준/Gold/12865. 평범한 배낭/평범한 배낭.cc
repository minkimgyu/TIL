#include <iostream>
using namespace std;

const int maxSize = 100 + 5;
const int maxWeight = 100000 + 5;
pair<int, int> arr[maxSize];

int dp[maxSize][maxWeight];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= arr[i].first)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];

	/*int result = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			result = max(result, dp[i][j]);
		}
	}*/

	//cout << result;
	return 0;
}