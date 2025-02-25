#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int dp[1000];

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

	int output = dp[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = arr[i];

		for (int j = 0; j < i; j++)
		{
			if (arr[i] <= arr[j]) continue;

			dp[i] = max(dp[i], dp[j] + arr[i]);
			output = max(output, dp[i]);
		}
	}

	cout << output;
	return 0;
}