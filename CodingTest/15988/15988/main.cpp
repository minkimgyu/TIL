#include <iostream>
using namespace std;

int n;
long long int dp[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;


	// mod 해도 1000000008 * 3은 충분히 int 범위를 넘어설 수 있다.
	// 그래서 long long int를 해줘야함
	for (int i = 4; i <= 1000000; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]+ dp[i - 3]) % 1000000009;
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		cout << dp[item];
		if (i != n - 1) cout << '\n';
	}

	return 0;
}