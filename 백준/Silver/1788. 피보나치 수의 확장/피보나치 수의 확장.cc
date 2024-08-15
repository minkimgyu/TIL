#include <iostream>
using namespace std;

const int mod = 1000000000;
const int dpSize = 1000000;
int dp[dpSize];

int fibo(int n)
{
	int mulit = 1;

	if (n < 0)
	{
		n *= -1;

		if (n % 2 == 0)
		{
			mulit *= -1;
		}
	}

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}

	return dp[n] * mulit;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int tmp = fibo(n);
	if (tmp < 0)
	{
		cout << -1 << '\n';
		cout << tmp * -1;
	}
	else if(tmp > 0)
	{
		cout << 1 << '\n';
		cout << tmp;
	}
	else
	{
		cout << 0 << '\n';
		cout << tmp;
	}

	return 0;
}