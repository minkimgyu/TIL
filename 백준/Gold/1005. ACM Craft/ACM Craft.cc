#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int buildingCount = 1000 + 5;

int buildingCost[buildingCount];
int indegree[buildingCount];

const int maxCost = 1000 * 100000 + 5;

int dp[buildingCount];

const int connectionCount = 100000 + 5;
vector<int> connections[connectionCount];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;

		// 초기화
		for (int z = 1; z <= n; z++)
		{
			dp[z] = 0;
			connections[z].clear();
			indegree[z] = 0;
			buildingCost[z] = 0;
		}

		for (int z = 1; z <= n; z++)
		{
			cin >> buildingCost[z];
		}

		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;

			indegree[y]++;
			connections[x].push_back(y);
		}

		int w;
		cin >> w;

		queue<int> q;
		for (int p = 1; p <= n; p++)
		{
			if (indegree[p] == 0)
			{
				q.push(p);
				dp[p] = buildingCost[p];
			}
		}

		while (q.empty() == false)
		{
			int front = q.front();
			q.pop();

			for (int a = 0; a < connections[front].size(); a++)
			{
				int nxt = connections[front][a];
				int nxtCost = buildingCost[nxt];

				dp[nxt] = max(dp[nxt], dp[front] + nxtCost);

				indegree[nxt]--;
				if (indegree[nxt] == 0) q.push(nxt);
			}
		}

		cout << dp[w];
		if (i != t - 1) cout << '\n';
	}

	return 0;
}