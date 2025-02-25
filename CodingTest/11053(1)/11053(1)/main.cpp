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

	int result = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] >= arr[i]) continue;

			dp[i] = max(dp[i], dp[j] + 1);
		}
		result = max(result, dp[i]);
	}

	cout << result + 1;
	return 0;
}