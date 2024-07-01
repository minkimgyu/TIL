#include <iostream>
using namespace std;

pair<long long int, long long int> dp[90];

int main()
{
	int n;
	cin >> n;

	// first가 0 second가 1

	dp[0].first = 0;
	dp[0].second = 1;

	for (int i = 1; i < n; i++)
	{
		dp[i].first += dp[i - 1].first;
		dp[i].second += dp[i - 1].first;

		dp[i].first += dp[i - 1].second;
	}

	cout << dp[n - 1].first + dp[n - 1].second;

	return 0;
}