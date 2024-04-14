#include <iostream>
using namespace std;

int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;

		// 나머지 연산 모두 해줘야 함

		if (i % 3 == 0) // 3로 나누어 떨어지는 경우
		{
			int tmp = dp[i / 3] + 1;
			if (dp[i] > tmp) dp[i] = tmp;
		}

		if (i % 2 == 0) // 2로 나누어 떨어지는 경우
		{
			int tmp = dp[i / 2] + 1; // 연산을 한번 했으므로 +1
			if (dp[i] > tmp) dp[i] = tmp;
		}
	}

	cout << dp[n];

	return 0;
}