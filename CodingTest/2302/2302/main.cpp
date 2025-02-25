#include <iostream>
#include <vector>
using namespace std;

int dp[45];
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> m;

	arr.push_back(0);
	for (int i = 0; i < m; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	arr.push_back(n + 1);

	int result = 1;
	int arrSize = arr.size();
	for (int i = 1; i < arrSize; i++)
	{
		result *= dp[arr[i] - arr[i - 1] - 1];
	}

	cout << result;

	return 0;
}