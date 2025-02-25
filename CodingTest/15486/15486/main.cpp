#include <iostream>
using namespace std;

pair<int, int> arr[1500051];
int dp[1500051];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (i + 1 <= n)
		{
			result = max(result, dp[i + 1]);
		}

		dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
		if (i + arr[i].first <= n)
		{
			result = max(result, dp[i + arr[i].first]);
		}
	}

	cout << result;
	return 0;
}