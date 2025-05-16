#include <iostream>
#include <map>
using namespace std;

const int maxSize = 100 + 5;
int arr[maxSize][maxSize];
long long int dp[maxSize][maxSize];

map<pair<pair<int, int>, pair<int, int>>, bool> block;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		pair<int, int> start, end;
		cin >> start.second >> start.first >> end.second >> end.first;

		pair<pair<int, int>, pair<int, int>> line1 = { { m - start.first, start.second }, { m - end.first, end.second } };
		pair<pair<int, int>, pair<int, int>> line2 = { { m - end.first, end.second }, { m - start.first, start.second } };

		block[line1] = true;
		block[line2] = true;
	}

	dp[m][0] = 1;

	for (int i = m - 1; i > -1; i--)
	{
		pair<pair<int, int>, pair<int, int>> line = { { i, 0 }, { i + 1, 0 } };
		if (block[line] == true) continue;

		dp[i][0] = dp[i + 1][0];
	}

	for (int j = 1; j <= n; j++)
	{
		pair<pair<int, int>, pair<int, int>> line = { { m, j }, { m, j - 1 } };
		if (block[line] == true) continue;

		dp[m][j] = dp[m][j - 1];
	}

	for (int i = m - 1; i > -1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (block[{ { i + 1, j }, { i, j } }] == true && block[{ { i, j - 1 }, { i, j } }] == false)
			{
				dp[i][j] = dp[i][j - 1];
			}
			else if (block[{ { i, j - 1 }, { i, j } }] == true && block[{ { i + 1, j }, { i, j } }] == false)
			{
				dp[i][j] = dp[i + 1][j];
			}
			else if (block[{ { i + 1, j }, { i, j } }] == false && block[{ { i, j - 1 }, { i, j } }] == false)
			{
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
			}
		}
	}

	cout << dp[0][n];
	return 0;
}