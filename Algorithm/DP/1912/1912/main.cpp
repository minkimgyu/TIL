#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;
int dp[maxSize];
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int result = -1000 + -5;

	for (int i = 1; i <= n; i++)
	{
		if (i == 1) dp[i] = arr[i];
		else dp[i] = max(dp[i - 1] + arr[i], arr[i]);

		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}