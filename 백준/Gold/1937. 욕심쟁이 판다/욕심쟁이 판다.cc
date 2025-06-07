#include <iostream>
using namespace std;

int n;

const int maxSize = 500 + 5;
int arr[maxSize][maxSize];
int dp[maxSize][maxSize];

pair<int, int> nearPoint[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool InRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n) return false;
	return true;
}

int dfs(pair<int, int> pos, int beforeValue)
{
	if (InRange(pos) == false) return 0;
	if (dp[pos.first][pos.second] != 0) return dp[pos.first][pos.second];

	dp[pos.first][pos.second] = 1;

	if (arr[pos.first - 1][pos.second] > arr[pos.first][pos.second])
	{
		dp[pos.first][pos.second] = max(dp[pos.first][pos.second], dfs({ pos.first - 1, pos.second }, arr[pos.first][pos.second]) + 1); // up
	}

	if (arr[pos.first + 1][pos.second] > arr[pos.first][pos.second])
	{
		dp[pos.first][pos.second] = max(dp[pos.first][pos.second], dfs({ pos.first + 1, pos.second }, arr[pos.first][pos.second]) + 1); // down
	}

	if (arr[pos.first][pos.second + 1] > arr[pos.first][pos.second])
	{
		dp[pos.first][pos.second] = max(dp[pos.first][pos.second], dfs({ pos.first, pos.second + 1 }, arr[pos.first][pos.second]) + 1); // right
	}

	if (arr[pos.first][pos.second - 1] > arr[pos.first][pos.second])
	{
		dp[pos.first][pos.second] = max(dp[pos.first][pos.second], dfs({ pos.first, pos.second - 1 }, arr[pos.first][pos.second]) + 1); // left
	}

	return dp[pos.first][pos.second];
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result = max(result, dfs({ i, j }, arr[i][j]));
		}
	}

	cout << result;
	return 0;
}