#include <iostream>
using namespace std;

const int maxSize = 101;
int dp[maxSize][10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;
	dp[1][4] = 1;
	dp[1][5] = 1;
	dp[1][6] = 1;
	dp[1][7] = 1;
	dp[1][8] = 1;
	dp[1][9] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][j + 1] += dp[i - 1][j] % 1000000000;
			}
			else if (j == 9)
			{
				dp[i][j - 1] += dp[i - 1][j] % 1000000000;
			}
			else
			{
				dp[i][j - 1] += dp[i - 1][j] % 1000000000;
				dp[i][j + 1] += dp[i - 1][j] % 1000000000;
			}
		}
	}

	long long int sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum += dp[n][i];
	}

	sum %= 1000000000; // 최종 값에 1000000000로 나눈 나머지를 구해야한다.

	cout << sum;
	return 0;
}