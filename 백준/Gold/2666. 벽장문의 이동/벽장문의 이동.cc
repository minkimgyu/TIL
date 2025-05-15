#include <iostream>
#include <algorithm>
using namespace std;

int arr[20 + 5];
int dp[20 + 5][20 + 5];

int openCount;

int dfs(int a, int b, int index)
{
	if (index == openCount) return 0;

	if (a < arr[index] && arr[index] < b)
	{
		return min(dfs(arr[index], b, index + 1) + arr[index] - a, dfs(a, arr[index], index + 1) + b - arr[index]);
	}
	else if (arr[index] < a)
	{
		return dfs(arr[index], b, index + 1) + a - arr[index];
	}
	else if (b < arr[index])
	{
		return dfs(a, arr[index], index + 1) + arr[index] - b;
	}
	else if (b == arr[index] || a == arr[index])
	{
		return dfs(a, b, index + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;
	
	cin >> openCount;

	for (int i = 0; i < openCount; i++)
	{
		cin >> arr[i];
	}

	cout << dfs(a, b, 0);
	return 0;
}