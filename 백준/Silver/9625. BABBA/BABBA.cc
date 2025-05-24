#include <iostream>
using namespace std;

pair<int, int> dp[45 + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i <= k; i++)
	{
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}

	cout << dp[k].first << " " << dp[k].second;
	return 0;
}