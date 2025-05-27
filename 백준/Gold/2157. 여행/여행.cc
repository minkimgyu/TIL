#include <iostream>
using namespace std;

const int maxCitySize = 300 + 5;
int path[maxCitySize][maxCitySize];
int dp[maxCitySize][maxCitySize];

int dfs(int n, int m)
{
	if (n != 1 && m == 1) return -987654321; // 마지막 칸에 도달했는데 칸이 1이 아닌 경우 매우 작은 값을 반환해서 max 업데이트 못하게 하기
	if (n == 1) return 0; // 맨 뒷 케이스 
	if (dp[n][m] != -1) return dp[n][m]; // 이미 값이 계산된 경우

	dp[n][m] = -987654321;

	for (int i = 1; i < n; i++)
	{
		// i는 n보다 작아야함
		if (path[i][n] == 0) continue;

		dp[n][m] = max(dp[n][m], dfs(i, m - 1) + path[i][n]);
	}

	return dp[n][m];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < maxCitySize; i++)
	{
		for (int j = 0; j < maxCitySize; j++)
		{
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < k; i++)
	{
		int start, end, value;
		cin >> start >> end >> value;
		path[start][end] = max(path[start][end], value);
	}

	cout << dfs(n, m);
	return 0;
}