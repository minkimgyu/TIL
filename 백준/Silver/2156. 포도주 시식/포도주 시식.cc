#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][10008];
int arr[10008];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		cout << arr[0];
		return 0;
	}

	int result = 0;
	dp[1][0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
		dp[1][i] = max(dp[1][i], dp[0][i - 1] + arr[i]);
		dp[2][i] = max(dp[2][i], dp[1][i - 1] + arr[i]);

		for (int j = 0; j < 3; j++)
		{
			if (dp[j][i] > result) result = dp[j][i];
		}
	}

	cout << result;
	return 0;
}