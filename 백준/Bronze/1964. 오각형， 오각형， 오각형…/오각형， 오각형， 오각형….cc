#include <iostream>
using namespace std;

int dp[10000001];

int main()
{
	int n;
	cin >> n;

	int start = 5;
	if (n == 1)
	{
		cout << start;
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		start = (start + 4 + (3 * (i - 1))) % 45678;
	}

	cout << start;
	return 0;
}