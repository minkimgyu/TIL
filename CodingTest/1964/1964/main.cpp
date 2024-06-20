#include <iostream>
using namespace std;

int dp[10000001];

int main()
{
	int n;
	cin >> n;

	dp[1] = 5;
	if (n == 1)
	{
		cout << dp[1];
		return 0;
	}

	int cnt = 10000001;
	for (int i = 2; i <= cnt; i++)
	{
		dp[i] = (dp[i - 1] + 4 + (3 * (i - 1))) % 45678;
	}

	cout << dp[n];
	return 0;
}