#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 1025;
int arr[maxSize][maxSize];
int dp[maxSize][maxSize];

const int offsetSize = 2;
pair<int, int> offset[offsetSize] =
{
	{-1, 0},
	{0, -1},
};

pair<int, int> crossOffset = { -1, -1 };

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int item;

			cin >> item;
			arr[i][j] = item;
			dp[i][j] = item;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < offsetSize; k++)
			{
				int x = j + offset[k].first;
				int y = i + offset[k].second;

				if (x < 0 || y < 0) continue;
				dp[i][j] += dp[y][x];
			}

			int x = j + crossOffset.first;
			int y = i + crossOffset.second;

			if (x < 0 || y < 0) continue;
			dp[i][j] -= dp[y][x];
		}
	}

	vector<int> results;

	for (int i = 0; i < m; i++)
	{
		pair<int, int> start;
		pair<int, int> end;

		cin >> start.second >> start.first >> end.second >> end.first;
		
		int result = dp[end.second][end.first] - dp[start.second - 1][end.first] - dp[end.second][start.first - 1] + dp[start.second - 1][start.first - 1];
		results.push_back(result);
	}

	int resultSize = results.size();
	for (int i = 0; i < resultSize; i++)
	{
		cout << results[i];
		if (i != resultSize - 1) cout << '\n';
	}

	return 0;
}