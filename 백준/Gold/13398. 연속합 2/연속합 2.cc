#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];
int dp[maxSize][2];

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

	int result = 100000 * -1000 - 5;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			// 1개면 무조건 선택해야함
			dp[i][0] = arr[i];
			dp[i][1] = 0;

			result = max(result, dp[i][0]);
		}
		else
		{
			dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]); // 스킵 없이 다음 값 구함 - 스킵하지 않은 경우
			dp[i][1] = max(dp[i - 1][1] + arr[i], arr[i]); // 스킵 없이 다음 값 구함 - 한번 스킵한 경우

			dp[i][1] = max(dp[i][1], dp[i - 1][0]); // 스킵한 경우

			result = max(result, max(dp[i][0], dp[i][1]));
		}
	}

	cout << result;
	return 0;
}