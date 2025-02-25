#include <iostream>
using namespace std;

const int maxSize = 100001;
//int dp[maxSize][3];
int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
	}

	cout << dp[n];


	/*dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;*/
	return 0;
}