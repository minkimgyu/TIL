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

	for (int i = 1; i <= n; i++)
	{
		int minValue = 10000 + 1;
		int maxValue = -1;

		for (int j = i; j >= 1; j--)
		{
			minValue = min(minValue, arr[j]);
			maxValue = max(maxValue, arr[j]);

			int gap = maxValue - minValue;
			dp[i] = max(dp[i], dp[j - 1] + gap);
		}
	}

	cout << dp[n];
	return 0;
}