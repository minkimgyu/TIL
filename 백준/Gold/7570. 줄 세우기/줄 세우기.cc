#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxSize = 1000000 + 5;
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
		dp[arr[i]] = i;
	}

	int result = 1;
	int maxResult = 1;

	for (int i = 2; i <= n; i++)
	{
		if (dp[i - 1] < dp[i]) result++;
		else result = 1;

		maxResult = max(maxResult, result);
	}

	cout << n - maxResult;
	return 0;
}