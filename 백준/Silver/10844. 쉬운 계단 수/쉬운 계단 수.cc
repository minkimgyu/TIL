#include <iostream>
using namespace std;

long long int dp[10][100];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int min = j - 1;
			int max = j + 1;

			int item = dp[j][i - 1] % 1000000000;
			
			if (min >= 0) dp[min][i] += item;
			if (max <= 9) dp[max][i] += item;
		}
	}

	long long int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += dp[i][n - 1];
	}

	result %= 1000000000;

	cout << result;

	return 0;
}