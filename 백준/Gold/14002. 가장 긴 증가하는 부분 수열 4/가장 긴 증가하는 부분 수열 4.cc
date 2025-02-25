#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000];
int dp[1000];

int visit[1000];

vector<int> resultLines;
void dfs(int index)
{
	if (index == -1) return;

	resultLines.push_back(arr[index]);
	dfs(visit[index]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = -1;
	int resultIndex = -1;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		visit[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] >= arr[i]) continue;

			if (dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				visit[i] = j;
			}
		}

		if (result < dp[i])
		{
			result = dp[i];
			resultIndex = i;
		}
	}

	cout << result + 1 << '\n';
	dfs(resultIndex);

	int resultLineSize = resultLines.size();
	for (int i = resultLineSize - 1; i >= 0; i--)
	{
		cout << resultLines[i];
		if (i != 0) cout << " ";
	}
}