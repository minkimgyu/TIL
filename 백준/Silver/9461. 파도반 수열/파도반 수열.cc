#include <iostream>
#include <vector>
using namespace std;

const int dpSize = 100;
long long int dp[dpSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 1;

	dp[3] = 2;
	dp[4] = 2;

	dp[5] = 3;
	dp[6] = 4;
	dp[7] = 5;

	for (int i = 8; i < dpSize; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	vector<long long int> results;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		results.push_back(dp[tmp - 1]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << results[i];
		if (i != n - 1) cout << '\n';
	}

	return 0;
}