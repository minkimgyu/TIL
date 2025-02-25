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
	// �� (k - 1�� �� + ���ǰ�)�� N�� �ȴٴ� ���� �� �� �ִ�.
	// dp ���� ����ٸ� ������ ����.
	// 
	// 
	// dp[k][n] = dp[k - 1][0] +  dp[k - 1][1] + dp[k - 1][2] + dp[k - 1][3] ... + dp[k - 1][n] �̴�.

	// k, n
	dp[0][0] = 1; // 0���� 0������ ���� 1���� ���ؼ� 0���� ����� ����� 1�� ������

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}

	// �� ���� �̿��ϸ�
	// dp[k][n - 1] = dp[k - 1][0] +  dp[k - 1][1] + dp[k - 1][2] + dp[k - 1][3] ... + dp[k - 1][n - 1]�̴�
	// �� �Ŀ��� dp[k - 1][n]�� �����ָ� dp[k][n] = dp[k][n - 1] + dp[k - 1][n]�̶�� ���� ���� �� �ִ�.
	// �� ������ε� dp���� © �� �ִ�.

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// �� ���ó�� �ڵ����� dp �迭�� ä������ �����Ƿ� ���� �־��ش�.
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