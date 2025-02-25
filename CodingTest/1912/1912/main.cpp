#include <iostream>
using namespace std;

int arr[100000];
int dp[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int result = -100000001;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	result = max(result, dp[0]);

	for (int i = 1; i < n; i++)
	{
		int item = max(arr[i] + dp[i - 1], arr[i]);
		dp[i] = item;

		result = max(result, item);
	}

	cout << result;
	return 0;
}