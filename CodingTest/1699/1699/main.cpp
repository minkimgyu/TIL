#include <iostream>
using namespace std;

// 2 = (2 - 1^2) + 1^2;
// 2 = 1 + 1^2
// --> 1 + 1;


// 20 = (20 - 1^2) + 1^2;
// 20 = (20 - 2^2) + 2^2;
// 20 = (20 - 3^2) + 3^2;
// 20 = (20 - 4^2) + 4^2;

// 4 = (4 - 1^2) + 1^2;
// 4 = (4 - 2^2) + 2^2; --> 이 경우는 0 + 2^2 이런 식으로 답이 1이 된다.

// 이 중 min 값을 찾는다.

int dp[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = i; // 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 --> 이런 식으로 최대 항의 개수로 초기화 해준다.
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}

	cout << dp[n];

	return 0;
}