#include <iostream>
using namespace std;

// 0 ~ 9
long long int dp[15][1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < 10; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				dp[j][i] += dp[k][i - 1] % 10007;
			}
		}
	}

	long long int result = 0;

	for (int i = 0; i < 10; i++)
	{
		result += dp[i][n - 1];
	}

	result %= 10007;
	cout << result;

	return 0;
}