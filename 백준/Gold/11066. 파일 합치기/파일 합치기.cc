#include <iostream>
using namespace std;

const int maxSize = 500 + 5;
int arr[maxSize];
int sum[maxSize];
int dp[maxSize][maxSize];

int fillDP(int start, int end)
{
	if (dp[start][end] != 2100000000) return dp[start][end];

	if (start == end) // 시작, 끝 범위가 같은 경우 ex) 2, 2
	{
		dp[start][end] = 0;
		return dp[start][end];
	}

	if (start + 1 == end) // 시작, 끝 범위 사이 개수가 1인 경우 ex) 2, 3
	{
		dp[start][end] = sum[end] - sum[start - 1];
		return dp[start][end];
	}

	for (int i = start; i < end; i++)
	{
		int left = fillDP(start, i);
		int right = fillDP(i + 1, end);
		dp[start][end] = min(dp[start][end], left + right);
	}

	//sum[end] - sum[start - 1]; 이거는 마지막 두 파일을 합칠 때 값을 더해주는 것
	dp[start][end] += sum[end] - sum[start - 1];
	return dp[start][end];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		int k;
		cin >> k;

		for (int i = 1; i <= k; i++)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				dp[i][j] = 2100000000;
			}
		}

		cout << fillDP(1, k);
		if (z != t - 1) cout << '\n';
	}
	
	return 0;
}