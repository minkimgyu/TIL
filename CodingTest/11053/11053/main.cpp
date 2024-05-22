#include <iostream>
using namespace std;

int dp[1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int max = 0;
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			cnt++;
			dp[i] = cnt;
		}
	}

	return 0;
}