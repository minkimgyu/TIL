#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[20000001];

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
		int tmp;
		cin >> tmp;

		if (dp[tmp + 10000000] > 0)
		{
			dp[tmp + 10000000] += 1;
		}
		else
		{
			arr[i] = tmp;
			dp[tmp + 10000000] = 1;
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int findNum;
		cin >> findNum;

		cout << dp[findNum + 10000000];
		if(i != m) cout << " ";
	}

	return 0;
}