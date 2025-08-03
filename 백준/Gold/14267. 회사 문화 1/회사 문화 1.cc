#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];
int dp[maxSize];

vector<int> connections[maxSize];
int n, m;

// 매 칭찬마다 돌리지 말고
// 모든 칭찬을 모았다가 한번에 쭉 더하면서 내려가보자
// 그럼 100,000 * 100,000이 아닌 100,000 * 1 안에 가능하다.

void dfs(int nxt, int w)
{
	if (nxt == 0) return; // 마지막은 넣지 않음

	dp[nxt] += w;

	for (int i = 0; i < connections[nxt].size(); i++)
	{
		dfs(connections[nxt][i], dp[nxt]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = n; i > 0; i--)
	{
		if (arr[i] == -1) continue;
		connections[arr[i]].push_back(i); // 직속 부하가 여러명일 수 있음
	}

	for (int j = 0; j < m; j++)
	{
		int i, w;
		cin >> i >> w;
		dp[i] += w;
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i];
		if (i != n) cout << " ";
	}

	return 0;
}