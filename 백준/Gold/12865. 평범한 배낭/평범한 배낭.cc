#include <iostream>
using namespace std;

const int maxSize = 100;
pair<int, int> arr[maxSize];

int dp[100 + 5][100000 + 5];

int knapseck(int i, int w)
{
	if (i <= 0 || w <= 0) return 0;

	if (arr[i].first > w)
	{
		return knapseck(i - 1, w);
	}
	else
	{
		int left = knapseck(i - 1, w);
		int right = knapseck(i - 1, w - arr[i].first);
		return max(left, arr[i].second + right);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;

		arr[i].first = w; // weight
		arr[i].second = v; // value
	}

	for (int i = 1; i <= n; i++)
	{
		for (int w = 1; w <= k; w++)
		{
			if (arr[i].first > w)
			{
				dp[i][w] = dp[i - 1][w];
			}
			else
			{
				dp[i][w] = max(dp[i - 1][w], arr[i].second + dp[i - 1][w - arr[i].first]);
			}
		}
	}

	cout << dp[n][k];
	return 0;
}