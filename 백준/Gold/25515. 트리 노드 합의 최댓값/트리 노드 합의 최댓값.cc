#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 100000 + 5;
vector<int> connections[maxSize];

long long int dp[maxSize];
int nodeValue[maxSize];

long long int dfs(int index)
{
	if (dp[index] != -maxSize) return dp[index];

	dp[index] = nodeValue[index];

	for (int i = 0; i < connections[index].size(); i++)
	{
		int goIndex = connections[index][i];
		dp[index] = max(dp[index], dp[index] + dfs(goIndex));
	}

	return dp[index];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> nodeValue[i];
	}

	for (int i = 0; i < n; i++)
	{
		dp[i] = -maxSize;
	}

	cout << dfs(0);
	return 0;
}