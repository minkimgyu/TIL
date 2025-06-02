#include <iostream>
#include <string>
using namespace std;

const int maxSize = 1000 + 5;
int arr[maxSize][maxSize];
int dp[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i - 1][0] + arr[i][0];
	}

	for (int i = 1; i < m; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}

	int result = 0;
	int minRectLength = max(n, m);
	for (int i = 0; i < minRectLength; i++)
	{
		int searchRow = n - i;
		int searchCol= m - i;

		for (int j = 0; j < searchRow; j++)
		{
			for (int k = 0; k < searchCol; k++)
			{
				pair<int, int> topLeft = {j, k};
				pair<int, int> bottomRight = { j + i, k + i };

				int sum;
				int left, up, cross;

				if (topLeft.first - 1 < 0 && topLeft.second - 1 < 0)
				{
					cross = 0;
					left = 0;
					up = 0;
				}
				else if(topLeft.first - 1 < 0)
				{
					cross = 0;
					up = 0;
					left = dp[bottomRight.first][topLeft.second - 1];
				}
				else if (topLeft.second - 1 < 0)
				{
					cross = 0;
					up = dp[topLeft.first - 1][bottomRight.second];
					left = 0;
				}
				else
				{
					cross = dp[topLeft.first - 1][topLeft.second - 1];
					up = dp[topLeft.first - 1][bottomRight.second];
					left = dp[bottomRight.first][topLeft.second - 1];
				}

				sum = dp[bottomRight.first][bottomRight.second]
					- left
					- up
					+ cross;

				int rect = (i + 1) * (i + 1);

				if (sum == rect)
				{
					result = rect;
				}
			}
		}
	}

	cout << result;
	return 0;
}