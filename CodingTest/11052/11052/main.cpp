#include <iostream>
using namespace std;

int arr[1005];
int dp[2100][1005];

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
		for (int j = 1; j <= n; j++)
		{
			dp[j][i] = dp[j][i - 1] + arr[i];

			dp[j][i] += arr[i] * i * j;
		}
	}

	return 0;
}