#include <iostream>
using namespace std;

int arr[3];
int dp[65][65][65];

int n;

int dfs(int a, int b = 0, int c = 0)
{
	if (a < 0) a = 0;
	if (b < 0) b = 0;
	if (c < 0) c = 0;

	// 모두 0보다 작다면 0 반환
	if (a <= 0 && b <= 0 && c <= 0) return 0;
	if (dp[a][b][c] != 65) return dp[a][b][c];

	dp[a][b][c] = min(dp[a][b][c], dfs(a - 9, b - 3, c - 1) + 1);
	dp[a][b][c] = min(dp[a][b][c], dfs(a - 9, b - 1, c - 3) + 1);

	dp[a][b][c] = min(dp[a][b][c], dfs(a - 3, b - 9, c - 1) + 1);
	dp[a][b][c] = min(dp[a][b][c], dfs(a - 1, b - 9, c - 3) + 1);

	dp[a][b][c] = min(dp[a][b][c], dfs(a - 1, b - 3, c - 9) + 1);
	dp[a][b][c] = min(dp[a][b][c], dfs(a - 3, b - 1, c - 9) + 1);

	return dp[a][b][c];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 60; i++)
	{
		for (int j = 0; j <= 60; j++)
		{
			for (int k = 0; k <= 60; k++)
			{
				dp[i][j][k] = 65;
			}
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if(n == 3) cout << dfs(arr[0], arr[1], arr[2]);
	else if(n == 2) cout << dfs(arr[0], arr[1]);
	else cout << dfs(arr[0]);

	return 0;
}