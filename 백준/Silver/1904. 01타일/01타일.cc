#include <iostream>
using namespace std;

int MOD = 15746;
const int maxSize = 1000001;
int dp[maxSize];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	cout << dp[n];
	return 0;
}