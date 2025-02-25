#include <iostream>
#include <algorithm>
using namespace std;

int t, w;
int dp[3][30][1000];
int inputs[1000];
// 이동 여부, 실행 횟수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> inputs[i];
	}

	int maxItemCount = 0;

	for (int i = 1; i <= t; i++)
	{
		for (int cnt = 0; cnt <= w; cnt++)
		{
			for (int pos = 1; pos <= 2; pos++)
			{
				int nextPos = inputs[i];

				if (pos == nextPos)
				{
					dp[pos][cnt][i] = dp[pos][cnt][i - 1] + 1;
					maxItemCount = max(maxItemCount, dp[pos][cnt][i]);
				}
				else
				{
					if (cnt > 0)
					{
						dp[nextPos][cnt - 1][i] = max(dp[nextPos][cnt - 1][i], dp[pos][cnt][i] + 1);
						maxItemCount = max(maxItemCount, dp[nextPos][cnt - 1][i]);
					}

					dp[pos][cnt][i] = dp[pos][cnt][i - 1];
					maxItemCount = max(maxItemCount, dp[pos][cnt][i]);
				}
			}
		}
	}

	cout << maxItemCount;
	return 0;
}