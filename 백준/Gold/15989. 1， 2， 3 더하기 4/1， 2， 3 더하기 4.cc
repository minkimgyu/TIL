#include <iostream>
using namespace std;

const int maxSize = 10000 + 5;

// 최대 수, 마지막 수
int dp[maxSize][4]; // 1, 2, 3

int dfs(int n, int lastNum)
{
	if (n < 0) return 0; // 연산 불가능 -> 0 반환해주기
	if (n == 0) return 1; // 마지막까지 연산 들어감
	if (dp[n][lastNum] != 0) return dp[n][lastNum]; // 이미 연산되었다면 반환

	// dp[n]은 경우의 수기 때문에 단 하나의 수만 나올수 있음 -> 최대, 최소값 불가능

	if (lastNum == 3)
	{
		dp[n][lastNum] = dfs(n - 1, 1) + dfs(n - 2, 2) + dfs(n - 3, 3);
	}
	else if (lastNum == 2)
	{
		dp[n][lastNum] = dfs(n - 1, 1) + dfs(n - 2, 2);
	}
	else if (lastNum == 1)
	{
		dp[n][lastNum] = dfs(n - 1, 1);
	}

	return dp[n][lastNum];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		cout << dfs(n, 3);

		if(i != t - 1) cout << '\n';

		for (int i = 0; i < 10000; i++)
			for (int j = 0; j < 4; j++)  // 1, 2, 3
				dp[i][j] = 0;
	}

	return 0;
}