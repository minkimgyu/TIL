#include <iostream>
#include <vector>
using namespace std;

const int mapSize = 500;
int map[mapSize][mapSize];

int dp[mapSize][mapSize];

const int offsetSize = 4;
pair<int, int> offset[offsetSize] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int dfs(int m, int n, pair<int, int> pos)
{
	if (pos.first == n - 1 && pos.second == m - 1) return 1;
	if (dp[pos.second][pos.first] != -1) return dp[pos.second][pos.first];

	dp[pos.second][pos.first] = 0;
	int value = map[pos.second][pos.first];

	for (int i = 0; i < offsetSize; i++)
	{
		int x = pos.first + offset[i].first;
		int y = pos.second + offset[i].second;

		if (x < 0 || x >= n || y < 0 || y >= m) continue;
		if (value <= map[y][x]) continue;

		dp[pos.second][pos.first] += dfs(m, n, { x, y });
	}

	return dp[pos.second][pos.first];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << dfs(m, n, { 0, 0 });
	return 0;
}