#include <iostream>
using namespace std;

const int maxSize = 1500000 + 100;
pair<int, int> arr[maxSize];
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
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i + 1] = max(dp[i + 1], dp[i]);
		dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
	}

	int result = 0;

	for (int i = 1; i <= n + 1; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}