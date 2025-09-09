#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 100000 + 5;
bool isVisible[maxSize];
long long int cost[maxSize];

const int maxConnectionSize = 300000 + 5;
vector<pair<int, int>> connections[maxConnectionSize]; // 목표, 시간

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> isVisible[i];
	}

	isVisible[n - 1] = false;

	for (int i = 0; i < m; i++)
	{
		int a, b, t;
		cin >> a >> b >> t;

		connections[a].push_back({t, b});
		connections[b].push_back({t, a});
	}

	long long int maxCost = 5;
	for (int i = 0; i < 100000; i++)
	{
		maxCost += 100000;
	}

	for (int i = 0; i < n; i++)
	{
		cost[i] = maxCost;
	}

	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pQ;
	pQ.push({ 0, 0 });
	cost[0] = 0;

	while (pQ.empty() == false)
	{
		pair<long long int, int> top = pQ.top();
		pQ.pop();

		long long int currentCost = top.first;
		if (cost[top.second] < currentCost) continue;

		for (int i = 0; i < connections[top.second].size(); i++)
		{
			long long int nxtCost = connections[top.second][i].first;
			int nxtIdx = connections[top.second][i].second;

			if (isVisible[nxtIdx] == true) continue; // 들킨다면 건너뛰기

			if (currentCost + nxtCost < cost[nxtIdx])
			{
				cost[nxtIdx] = currentCost + nxtCost;
				pQ.push({ currentCost + nxtCost, nxtIdx });
			}
		}
	}

	if (cost[n - 1] == maxCost)
	{
		cout << -1;
	}
	else
	{
		cout << cost[n - 1];
	}

	return 0;
}