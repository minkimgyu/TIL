#include <iostream>
#include <vector>
using namespace std;

int dp[1000];

int main()
{
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n - 1];
	return 0;
}