#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000 + 5;
int arr[maxSize][3];
int dp[maxSize][3][3];
// value, ToColor, StartColor
// 0, 1, 2 --> 나누기
// r, g, b

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	const int maxSize = 100000000;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

		dp[i][0][0] = maxSize;
		dp[i][0][1] = maxSize;
		dp[i][0][2] = maxSize;

		dp[i][1][0] = maxSize;
		dp[i][1][1] = maxSize;
		dp[i][1][2] = maxSize;

		dp[i][2][0] = maxSize;
		dp[i][2][1] = maxSize;
		dp[i][2][2] = maxSize;
	}

	dp[1][0][0] = arr[1][0];
	dp[1][1][1] = arr[1][1];
	dp[1][2][2] = arr[1][2];

	for (int i = 2; i <= n; i++)
	{
		if (i < n)
		{
			dp[i][0][0] = min(dp[i - 1][1][0] + arr[i][0], dp[i - 1][2][0] + arr[i][0]); // 0에서 시작한 1, 2 케이스
			dp[i][0][1] = min(dp[i - 1][1][1] + arr[i][0], dp[i - 1][2][1] + arr[i][0]); // 1에서 시작한 1, 2 케이스
			dp[i][0][2] = min(dp[i - 1][1][2] + arr[i][0], dp[i - 1][2][2] + arr[i][0]); // 2에서 시작한 1, 2 케이스

			dp[i][1][0] = min(dp[i - 1][0][0] + arr[i][1], dp[i - 1][2][0] + arr[i][1]); // 0에서 시작한 0, 2 케이스
			dp[i][1][1] = min(dp[i - 1][0][1] + arr[i][1], dp[i - 1][2][1] + arr[i][1]); // 1에서 시작한 0, 2 케이스
			dp[i][1][2] = min(dp[i - 1][0][2] + arr[i][1], dp[i - 1][2][2] + arr[i][1]); // 2에서 시작한 0, 2 케이스

			dp[i][2][0] = min(dp[i - 1][0][0] + arr[i][2], dp[i - 1][1][0] + arr[i][2]); // 0에서 시작한 0, 1 케이스
			dp[i][2][1] = min(dp[i - 1][0][1] + arr[i][2], dp[i - 1][1][1] + arr[i][2]); // 1에서 시작한 0, 1 케이스
			dp[i][2][2] = min(dp[i - 1][0][2] + arr[i][2], dp[i - 1][1][2] + arr[i][2]); // 2에서 시작한 0, 1 케이스
		}
		else
		{
			dp[i][0][1] = min(dp[i - 1][1][1] + arr[i][0], dp[i - 1][2][1] + arr[i][0]); // 1에서 시작한 1, 2 케이스
			dp[i][0][2] = min(dp[i - 1][1][2] + arr[i][0], dp[i - 1][2][2] + arr[i][0]); // 2에서 시작한 1, 2 케이스

			dp[i][1][0] = min(dp[i - 1][0][0] + arr[i][1], dp[i - 1][2][0] + arr[i][1]); // 0에서 시작한 0, 2 케이스
			dp[i][1][2] = min(dp[i - 1][0][2] + arr[i][1], dp[i - 1][2][2] + arr[i][1]); // 2에서 시작한 0, 2 케이스

			dp[i][2][0] = min(dp[i - 1][0][0] + arr[i][2], dp[i - 1][1][0] + arr[i][2]); // 0에서 시작한 0, 1 케이스
			dp[i][2][1] = min(dp[i - 1][0][1] + arr[i][2], dp[i - 1][1][1] + arr[i][2]); // 1에서 시작한 0, 1 케이스
		}
	}

	int result = maxSize;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result = min(result, dp[n][i][j]);
		}
	}

	cout << result;
	return 0;
}