#include <iostream>
using namespace std;

int zeroCount = 0;
int oneCount = 0;

const int maxFiboCount = 41;
pair<int, int> dp[maxFiboCount];

int main()
{
	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i < maxFiboCount; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		cout << dp[item].first << " " << dp[item].second;
		if (i != n - 1) cout << '\n';
	}

	return 0;
}