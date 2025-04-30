#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;
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
	dp[3] = 3;

	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n];
	return 0;
}