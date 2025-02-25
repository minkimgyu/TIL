#include <iostream>
using namespace std;

int dp[1000001];
int visit[1000001];

void dfs(int index)
{
	if (index == 0) return;
	cout << index << " ";

	dfs(visit[index]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	visit[1] = 0;
	visit[2] = 1;
	visit[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			int arr[3] = { i - 1, i / 2, i / 3 };

			int minIndex = -1;
			int min = 1000001;

			for (int j = 0; j < 3; j++)
			{
				if (min > dp[arr[j]])
				{
					min = dp[arr[j]];
					minIndex = arr[j];
				}
			}

			dp[i] = min + 1;
			// 10, 9, 3, 1
			visit[i] = minIndex;
		}
		else if (i % 2 == 0)
		{
			int arr[2] = { i - 1, i / 2};

			int minIndex = -1;
			int min = 1000001;

			for (int j = 0; j < 2; j++)
			{
				if (min > dp[arr[j]])
				{
					min = dp[arr[j]];
					minIndex = arr[j];
				}
			}

			dp[i] = min + 1;
			// 10, 9, 3, 1
			visit[i] = minIndex;
		}
		else if (i % 3 == 0)
		{
			int arr[2] = { i - 1, i / 3 };

			int minIndex = -1;
			int min = 1000001;

			for (int j = 0; j < 2; j++)
			{
				if (min > dp[arr[j]])
				{
					min = dp[arr[j]];
					minIndex = arr[j];
				}
			}

			dp[i] = min + 1;
			// 10, 9, 3, 1
			visit[i] = minIndex;
		}
		else
		{
			dp[i] = dp[i - 1] + 1;

			// 10, 9, 3, 1
			visit[i] = i - 1;
		}
	}

	cout << dp[n] << '\n';
	dfs(n);
	return 0;
}