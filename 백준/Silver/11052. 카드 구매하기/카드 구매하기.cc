#include <iostream>
using namespace std;

const int maxSize = 1000 + 5;
int arr[maxSize];
int dp[maxSize];

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

	dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i] = max(dp[i], dp[j] + arr[i - j]);
		}
		dp[i] = max(dp[i], arr[i]);
	}

	cout << dp[n];

	return 0;
}