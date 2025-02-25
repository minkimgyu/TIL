#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000000 + 5;
int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= x; i++)
	{
		int minCount = maxSize;

		if (i % 2 == 0)
		{
			minCount = min(minCount, dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			minCount = min(minCount, dp[i / 3] + 1);
		}
		minCount = min(minCount, dp[i - 1] + 1);

		dp[i] = minCount;
	}

	cout << dp[x];

	return 0;
}