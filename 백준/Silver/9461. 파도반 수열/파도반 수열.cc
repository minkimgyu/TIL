#include <iostream>
using namespace std;

const int maxCount = 100;
const int maxSize = maxCount + 5;
long long int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= maxCount; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		cout << dp[n];

		if (i != t) cout << '\n';
	}

	return 0;
}