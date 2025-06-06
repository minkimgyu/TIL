#include <iostream>
#include <limits.h>
using namespace std;

int n;
const int maxSize = 500 + 5;
int dp[maxSize][maxSize];

pair<int, int> inputs[maxSize];

int dfs(int start, int end)
{
	if (dp[start][end] != INT_MAX) return dp[start][end]; // 이미 연산된 경우 스킵

	if (start == end) return 0; // 범위 내에 1개인 경우 

	if (end - start == 1) // 범위 내에 2개인 경우
	{
		dp[start][end] = inputs[start].first * inputs[start].second * inputs[end].second;
		return dp[start][end];
	}

	int minValue = INT_MAX - 1;

	for (int i = start; i < end; i++)
	{
		int first = dfs(start, i);
		int second = dfs(i + 1, end);

		int additional = inputs[start].first * inputs[i].second * inputs[end].second; // 현제 범위 연산

		minValue = min(minValue, first + second + additional); // 마지막 비교
	}

	dp[start][end] = minValue;
	return minValue;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> inputs[i].first >> inputs[i].second;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}

	cout << dfs(1, n);
	return 0;
}