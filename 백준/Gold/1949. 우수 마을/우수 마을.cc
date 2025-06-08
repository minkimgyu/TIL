#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 10000 + 5;
int arr[maxSize];
int dp[maxSize][2]; // 0 일반 마을, 1 우수 마을
bool visit[maxSize];

vector<int> connections[maxSize];

void dfs(int index)
{
	dp[index][0] = 0;
	dp[index][1] = arr[index];
	visit[index] = true;

	for (int i = 0; i < connections[index].size(); i++)
	{
		int goIndex = connections[index][i];
		if (visit[goIndex] == true) continue;
		dfs(goIndex);

		dp[index][0] += max(dp[goIndex][0], dp[goIndex][1]);
		dp[index][1] += dp[goIndex][0];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 2; i <= n; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
		connections[end].push_back(start);
	}

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);
	return 0;
}