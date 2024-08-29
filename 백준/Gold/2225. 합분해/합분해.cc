#include <iostream>
using namespace std;

int n, k, result = 0;
const int maxSize = 201;
const int MOD = 1000000000;
int dp[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	// 5 + 0 = 5
	// 4 + 1 = 5
	// 3 + 2 = 5
	// 2 + 3 = 5
	// 1 + 4 = 5
	// 0 + 5 = 5
	// 
	// ? + ? + M = N
	// 즉 (k - 1의 값 + 임의값)은 N이 된다는 것을 알 수 있다.
	// dp 식을 세운다면 다음과 같다.
	// dp[k][n] = dp[k - 1][0] +  dp[k - 1][1] + dp[k - 1][2] + dp[k - 1][3] ... + dp[k - 1][n] 이다.

	// k, n
	dp[0][0] = 1; // 0부터 0까지의 정수 1개를 더해서 0으로 만드는 방법은 1개 존재함

	//for (int i = 1; i <= k; i++)
	//{
	//	for (int j = 0; j <= n; j++)
	//	{
	//		for (int k = 0; k <= j; k++)
	//		{
	//			dp[i][j] += dp[i - 1][k];
	//			dp[i][j] %= MOD;
	//		}
	//	}
	//}

	// 위 식을 이용하면
	// dp[k][n - 1] = dp[k - 1][0] +  dp[k - 1][1] + dp[k - 1][2] + dp[k - 1][3] ... + dp[k - 1][n - 1]이다
	// 위 식에서 dp[k - 1][n]을 더해주면 dp[k][n] = dp[k][n - 1] + dp[k - 1][n]이라는 식을 얻을 수 있다.
	// 이 방법으로도 dp식을 짤 수 있다.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j == 1) {
				dp[i][j] = 1;
			}
			else if (i == 1) {
				dp[i][j] = j;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
			}
		}
	}
	
	cout << dp[n][k];
	return 0;
}