#include <iostream>
using namespace std;

const int maxSize = 1000 + 5;
int arr[maxSize][maxSize];
long long int dp[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 2; i <= r; i++)
	{
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}

	for (int j = 2; j <= c; j++)
	{
		dp[1][j] = dp[1][j - 1] + arr[1][j];
	}

	for (int i = 2; i <= r; i++)
	{
		for (int j = 2; j <= c; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		long long int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		long long int result = dp[r2][c2] - (dp[r2][c1 - 1] + dp[r1 - 1][c2]) + dp[r1 - 1][c1 - 1];
		result /= ((r2 - r1 + 1) * (c2 - c1 + 1));

		cout << result;
		if (i != k - 1) cout << '\n';
	}

	return 0;
}