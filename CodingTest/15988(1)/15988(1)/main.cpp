#include <iostream>
using namespace std;

const int maxSize = 1000001;
long long int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < maxSize; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	}

	int t;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		int cnt;
		cin >> cnt;
		cout << dp[cnt];

		if (j != t - 1) cout << '\n';
	}

	return 0;
}