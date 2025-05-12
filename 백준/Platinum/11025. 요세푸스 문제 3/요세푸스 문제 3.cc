#include <iostream>
using namespace std;

//int dp[5000000 + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int start = 0;

	for (int i = 2; i <= n; i++)
	{
		start = (start + k) % i;
	}

	cout << start + 1;
	return 0;
}