#include <iostream>
#include <string>
using namespace std;

string input;
const int maxSize = 500 + 5;
int dp[maxSize][maxSize];

int dfs(int start, int end)
{
	if (start >= end) return 0;
	if (dp[start][end] != -1) return dp[start][end];

	if (input[start] == 'a' && input[end] == 't' ||
		input[start] == 'g' && input[end] == 'c')
	{
		dp[start][end] = max(dp[start][end], dfs(start + 1, end - 1) + 2);
	}

	for (int i = start; i < end; i++)
	{
		int left = dfs(start, i);
		int right = dfs(i + 1, end);
		dp[start][end] = max(dp[start][end], left + right);
	}

	return dp[start][end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			dp[i][j] = -1;
		}
	}

	cin >> input;
	cout << dfs(0, input.size() - 1);
	return 0;
}