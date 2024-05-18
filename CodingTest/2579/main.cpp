#include <iostream>
#include <algorithm>
using namespace std;

// 1, 2, 3 ... 300
// 0, 1, 2, 3
int dp[310][3]{ 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n + 10];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1][1] = arr[1];
	dp[1][2] = arr[1];

	for (int i = 0; i <= n; i++)
	{
		dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][1] + arr[i + 2], dp[i][2] + arr[i + 2]));
		dp[i + 1][2] = max(dp[i + 1][2], dp[i][1] + arr[i + 1]);
	}

	cout << max(dp[n][1], dp[n][2]);
	return 0;
}