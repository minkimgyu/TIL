#include <iostream>
using namespace std;

const int maxSize = 2000 + 5;
int arr[maxSize];

int dp[maxSize][maxSize];
int n, m;

int dfs(int start, int end)
{
	if (dp[start][end] != -1) return dp[start][end]; // 이미 값이 등록된 경우

	if (end - start == 0) // 범위가 1인 경우 팰린드롬
	{
		dp[start][end] = 1;
		return dp[start][end];
	}
	else if (end - start == 1) // 범위가 2인 경우, 값이 같다면 팰린드롬
	{
		if (arr[start] == arr[end]) dp[start][end] = 1;
		else dp[start][end] = 0;

		return dp[start][end];
	}

	bool hasInnerPalindrome = dfs(start + 1, end - 1);
	if (hasInnerPalindrome == 1 && arr[start] == arr[end]) dp[start][end] = 1;
	else dp[start][end] = 0;

	return dp[start][end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dfs(i, j);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << dp[start][end];
		if(i != m - 1) cout << '\n';
	}

	return 0;
}