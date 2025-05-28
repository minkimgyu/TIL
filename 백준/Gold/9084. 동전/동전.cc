#include <iostream>
using namespace std;

const int maxSize = 10000 + 5;
int dp[maxSize];

int n;

const int coinSize = 20 + 5;
int arr[coinSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int m;
		cin >> m;

		for (int i = 0; i <= m; i++)
		{
			if (i % arr[0] == 0) dp[i] = 1;
		}

		for (int j = 1; j < n; j++)
		{
			for (int i = 0; i <= m; i++)
			{
				if (i >= arr[j])
				{
					dp[i] = dp[i] + dp[i - arr[j]];
				}
			}
		}

		cout << dp[m];
		if (t != 0) cout << '\n';

		for (int i = 0; i < maxSize; i++)
		{
			dp[i] = 0;
		}
	}

	return 0;
}