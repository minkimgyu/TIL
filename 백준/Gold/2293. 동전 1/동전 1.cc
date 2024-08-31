#include <iostream>
using namespace std;

int dp[10001];
int coin[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1; // 가치의 합이 0인 동전들의 합은 어떤 동전도 선택하지 않는 경우라고 생각하면 된다.

	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			 dp[j] = dp[j] + dp[j - coin[i]];

			// 가치의 합이 5가 되려면
			// 가치가 1인 동전 1개와 가치의 합이 4인 동전들을 합한 경우다.
			// 따라서 가치의 합이 4인 경우의 수와 같다는 것이다.
			// 
			// 이런 방식으로 가치가 3인 동전의 경우
			// dp[3] = dp[3] + 1 --> 가치 3인 동전 하나를 선택하는 것과 같다.
			// dp[4] = dp[4] + dp[1] --> 가치의 합이 1인 동전들의 경우와 가치가 3인 동전을 선택하는 것과 같다.
			// dp[5] = dp[5] + dp[2] --> 가치의 합이 2인 동전들의 경우와 가치가 3인 동전을 선택하는 것과 같다.
			// dp[k] = dp[k] + dp[k - 3] --> 가치의 합이 k - 3인 동전들의 경우와 가치가 3인 동전을 선택하는 것과 같다.
			// 이런 식으로 모든 경우의 수를 탐색한다.
		}
	}

	cout << dp[k];
	return 0;
}