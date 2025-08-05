#include <iostream>
using namespace std;

const int maxSize = 100 + 5;
int arr[maxSize];

const int maxSumSize = 2000 + 5;
long long int dp[maxSize][maxSumSize];

int n;

long long int dfs(int idx, int sum)
{
	if (sum < 0 || sum > 20) return 0; // 합이 0보다 작은 경우 또는 20보다 큰 경우 0 반환 -> 성립 불가능한 식임
	if (dp[idx][sum] != -1) return dp[idx][sum]; // -1이 아닌 경우 -> 이미 계산된 경우임
	
	if (idx == n - 1)
	{
		if (sum == arr[n - 1])
		{
			return 1; // 올바르게 결과가 나오는 경우 1 반환
		}
		else
		{
			return 0; // 알맞지 않는 결과가 나오는 경우 0 반환
		}
	}

	if (idx == 0)
	{
		dp[idx][sum] = dfs(idx + 1, sum + arr[idx]);
	}
	else
	{
		dp[idx][sum] = dfs(idx + 1, sum + arr[idx]) + dfs(idx + 1, sum - arr[idx]);
	}

	return dp[idx][sum];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSumSize; j++)
		{
			dp[i][j] = -1;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << dfs(0, 0);
	return 0;
}