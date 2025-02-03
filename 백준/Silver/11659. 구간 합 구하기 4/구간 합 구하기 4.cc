#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];
int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;

		cout << dp[en] - dp[st - 1];
		if (i != m - 1) cout << '\n';
	}

	return 0;
}