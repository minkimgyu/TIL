#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100000 + 10;
int arr[3][maxSize];
int dp[3][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		for (int j = 1; j <= n; j++) cin >> arr[1][j];
		for (int j = 1; j <= n; j++) cin >> arr[2][j];

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];

		for (int k = 1; k <= n; k++)
		{
			dp[0][k + 1] = max(dp[0][k + 1], dp[0][k]);
			dp[1][k + 1] = max(dp[1][k + 1], dp[0][k] + arr[1][k + 1]);
			dp[2][k + 1] = max(dp[2][k + 1], dp[0][k] + arr[2][k + 1]);

			dp[0][k + 1] = max(dp[0][k + 1], dp[1][k]);
			dp[2][k + 1] = max(dp[2][k + 1], dp[1][k] + arr[2][k + 1]);

			dp[0][k + 1] = max(dp[0][k + 1], dp[2][k]);
			dp[1][k + 1] = max(dp[1][k + 1], dp[2][k] + arr[1][k + 1]);
		}

		cout << max(dp[0][n], max(dp[1][n], dp[2][n]));
		if(i != t - 1) cout << '\n';

		// reset
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				arr[k][j] = 0;
			}
		}

		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				dp[k][j] = 0;
			}
		}
	}

	return 0;
}