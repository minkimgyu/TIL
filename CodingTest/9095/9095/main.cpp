#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		int targetNum = arr[i];

		int dp[12]{ 0 };
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= targetNum; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}

		cout << dp[targetNum] << '\n';
	}

	return 0;
}