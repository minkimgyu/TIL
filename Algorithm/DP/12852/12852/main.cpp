#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000000 + 5;
int dp[maxSize];
int trace[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 0;

	fill(dp + 2, dp + n + 1, maxSize);

	for (int i = 2; i <= n; i++)
	{
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
			trace[i] = i / 3;
		}

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
			trace[i] = i / 2;
		}

		if (dp[i] > dp[i - 1] + 1)
		{
			dp[i] = min(dp[i], dp[i - 1] + 1);
			trace[i] = i - 1;
		}
	}

	cout << dp[n] << '\n';

	int current = n;
	while (current != 0)
	{
		cout << current << " ";
		current = trace[current];
	}

	return 0;
}