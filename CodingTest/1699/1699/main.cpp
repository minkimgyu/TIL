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
// 4 = (4 - 2^2) + 2^2; --> �� ���� 0 + 2^2 �̷� ������ ���� 1�� �ȴ�.

// �� �� min ���� ã�´�.

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
		dp[i] = i; // 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 1^2 --> �̷� ������ �ִ� ���� ������ �ʱ�ȭ ���ش�.
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