#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxSize = 1000 + 5;

// value, index
vector<pair<int, int>> adj[maxSize];

int result[maxSize][maxSize]; // 1000 * 1000

#define Cost first
#define Index second

int main()
{
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int start, end, t;
		cin >> start >> end >> t;

		adj[start].push_back({ t, end });
	}

	for (int z = 1; z <= n; z++)
	{
		fill(result[z], result[z] + n + 5, 200000000);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
		pQ.push({ 0, z });
		result[z][z] = 0;

		while (pQ.empty() == false)
		{
			pair<int, int> front = pQ.top(); pQ.pop();
			if (result[z][front.Index] != front.Cost) continue;

			int cost = front.Cost;

			for (int i = 0; i < adj[front.Index].size(); i++)
			{
				pair<int, int> nxt = adj[front.Index][i];

				int nxtCost = cost + nxt.Cost;
				if (result[z][nxt.Index] <= nxtCost) continue;

				result[z][nxt.Index] = nxtCost;
				pQ.push({ nxtCost, nxt.Index }); // 다음 비용, 다음 인덱스
			}
		}
	}

	int maxCost = 0;

	for (int i = 1; i <= n; i++)
	{
		int totalCost = result[i][x] + result[x][i];
		maxCost = max(maxCost, totalCost);
	}

	cout << maxCost;
	return 0;
}