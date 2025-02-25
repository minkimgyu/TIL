#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 500 + 5;
int map[maxSize][maxSize];
int dp[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int item;
			cin >> item;
			map[i][j] = item;
		}
	}

	dp[0][0] = map[0][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i + 1][j] = max(dp[i + 1][j], map[i + 1][j] + dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], map[i + 1][j + 1] + dp[i][j]);
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result = max(result, dp[n - 1][i]);
	}

	cout << result;
	return 0;
}