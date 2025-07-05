#include <iostream>
using namespace std;

const int maxSize = 2000 + 5;
int arrL[maxSize];
int arrR[maxSize];

int dp[maxSize][maxSize];

int n;

int dfs(int left, int right)
{
	if (dp[left][right] != -1) return dp[left][right]; // 이미 연산한 경우
	if (left == n + 1 || right == n + 1) return 0; // 끝에 도달한 경우

	int leftValue = dfs(left + 1, right);
	int bothValue = dfs(left + 1, right + 1);
	int rightValue = -1;
	if (arrL[left] > arrR[right]) rightValue = dfs(left, right + 1) + arrR[right]; // 왼쪽이 더 큰 경우 오른쪽 값 더하기

	return max(rightValue, max(leftValue, bothValue));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arrL[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arrR[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = -1;
		}
	}

	cout << dfs(1, 1);

	return 0;
}