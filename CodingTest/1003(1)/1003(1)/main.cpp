#include <iostream>
using namespace std;

const int maxFibo = 41;
pair<int, int> dp[maxFibo];

// 엣지 케이스 조심!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };

	for (int i = 2; i < maxFibo; i++)
	{
		int zeroCount = dp[i - 1].first + dp[i - 2].first;
		int oneCount = dp[i - 1].second + dp[i - 2].second;
		dp[i] = { zeroCount, oneCount };
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int loopCnt;
		cin >> loopCnt;

		cout << dp[loopCnt].first << " " << dp[loopCnt].second;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}