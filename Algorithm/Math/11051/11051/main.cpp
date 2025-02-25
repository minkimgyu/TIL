#include <iostream>
using namespace std;

const int maxSize = 1000 + 5;
long long int dp[maxSize][maxSize];

const int divide = 10007;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i < maxSize; i++)
	{
		dp[i][0] = dp[i][i] = 1; // i == j인 경우는 여기서 채운다.
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % divide;
		}
	}

	cout << dp[n][k];

	// 5c3 = 4c2 + 4c3
	// 
	// 4c2 = 3c1 + 3c2
	// 
	// 3c2 = 2c1 + 2c2
	//
	// 2c2 = 1c1 + 1c2
	// 1c2 = 



	return 0;
}