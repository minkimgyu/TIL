#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 20000 + 5;
int cost[maxSize];

const int INF = 20000 * 10 + 5;
vector<pair<int, int>> connections[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int k;
	cin >> k;

	for (int i = 0; i < e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		connections[a].push_back({w, b});
	}

	for (int i = 1; i <= v; i++)
	{
		cost[i] = INF;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
	pQ.push({ 0, k });
	cost[k] = 0;

	while (pQ.empty() == false)
	{
		pair<int, int> top = pQ.top(); pQ.pop();

		for (int i = 0; i < connections[top.second].size(); i++)
		{
			int nxtIdx = connections[top.second][i].second;
			int nxtCost = top.first + connections[top.second][i].first;

			if (cost[nxtIdx] > nxtCost)
			{
				cost[nxtIdx] = nxtCost;
				pQ.push({ cost[nxtIdx], nxtIdx });
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (cost[i] == INF) cout << "INF";
		else cout << cost[i];

		if(i != v) cout << '\n';
	}

	return 0;
}