#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize][3];
int dp[maxSize][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int loopCount = 0;

	while(1)
	{
		int n;
		cin >> n;

		loopCount++;
		if (n == 0) break;

		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = 0;
				dp[i][j] = 1000000;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> arr[i][j];
				dp[i][j] = 1000000;
			}
		}

		dp[0][1] = arr[0][1];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == 0)
				{
					if (j == 1)
					{
						dp[i][2] = min(dp[i][2], dp[i][1] + arr[i][2]);
						dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + arr[i + 1][2]);
						dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + arr[i + 1][1]);
						dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + arr[i + 1][0]);
					}
					else if (j == 2)
					{
						dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + arr[i + 1][2]);
						dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + arr[i + 1][1]);
					}
				}
				else
				{
					if (j == 0)
					{
						dp[i][1] = min(dp[i][1], dp[i][0] + arr[i][1]);
						dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + arr[i + 1][1]);
						dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + arr[i + 1][0]);
					}
					else if (j == 1)
					{
						dp[i][2] = min(dp[i][2], dp[i][1] + arr[i][2]);
						dp[i + 1][2] = min(dp[i + 1][2], dp[i][1] + arr[i + 1][2]);
						dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + arr[i + 1][1]);
						dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + arr[i + 1][0]);
					}
					else if (j == 2)
					{
						dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + arr[i + 1][2]);
						dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + arr[i + 1][1]);
					}
				}
			}
		}

		cout << loopCount << ". " << dp[n - 1][1] << '\n';
	}
	
	return 0;
}