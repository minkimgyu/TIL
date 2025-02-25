#include <iostream>
using namespace std;

const int maxSize = 40 + 5;
pair<int, int> dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i < maxSize; i++)
	{
		dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };
	}

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << dp[n].first << " " << dp[n].second;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}