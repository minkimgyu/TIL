#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int maxSize = 2000 + 5;
int costs1[maxSize];
int costs2[maxSize];
vector<pair<int, int>> connections[maxSize];

vector<int> targets;

const int INF = 1000000000 + 5;

bool visits1[maxSize];
bool visits2[maxSize];

void dijkstra(int n, int start)
{
	for (int i = 1; i <= n; i++)
	{
		costs1[i] = INF;
		visits1[i] = false;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
	pQ.push({0, start });
	costs1[start] = 0;

	while (pQ.empty() == false)
	{
		pair<int, int> top = pQ.top(); pQ.pop();

		int currentIdx = top.second;
		int currentCost = top.first;

		if (visits1[currentIdx] == true) continue;
		visits1[currentIdx] = true;

		for (int i = 0; i < connections[currentIdx].size(); i++)
		{
			int nxtIdx = connections[currentIdx][i].second;
			int nxtCost = connections[currentIdx][i].first;

			int cost = nxtCost + currentCost;
			if (costs1[nxtIdx] >= cost)
			{
				costs1[nxtIdx] = cost;
				pQ.push({ cost, nxtIdx });
			}
		}
	}
}

void dijkstra1(int n, int start)
{
	for (int i = 1; i <= n; i++)
	{
		costs2[i] = INF;
		visits2[i] = false;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
	pQ.push({ 0, start });
	costs2[start] = 0;

	while (pQ.empty() == false)
	{
		pair<int, int> top = pQ.top(); pQ.pop();

		int currentIdx = top.second;
		int currentCost = top.first;

		if (visits2[currentIdx] == true) continue;
		visits2[currentIdx] = true;

		for (int i = 0; i < connections[currentIdx].size(); i++)
		{
			int nxtIdx = connections[currentIdx][i].second;
			int nxtCost = connections[currentIdx][i].first;

			int cost = nxtCost + currentCost;
			if (costs2[nxtIdx] >= cost)
			{
				costs2[nxtIdx] = cost;
				pQ.push({ cost, nxtIdx });
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int z = 0; z < T; z++)
	{
		// 초기화
		for (int i = 0; i < maxSize; i++) connections[i].clear();
		targets.clear();

		int n, m, t;
		cin >> n >> m >> t;

		int s, g, h;
		cin >> s >> g >> h;

		int gHCost = 0;

		for (int i = 0; i < m; i++)
		{
			int a, b, d;
			cin >> a >> b >> d;

			if ((a == g && b == h) || (a == h && b == g)) gHCost = d;

			connections[a].push_back({ d, b });
			connections[b].push_back({ d, a });
		}

		dijkstra(n, s);

		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;

			targets.push_back(x);
		}

		sort(targets.begin(), targets.end());

		for (int i = 0; i < targets.size(); i++)
		{
			int x = targets[i];
			if (costs1[x] == INF) continue;

			// (s -> g) + (g -> h) + (h -> 가능한 x)
			// (s -> h) + (h -> g) + (g -> 가능한 x)
			// 둘 중 최단 거리와 같은 케이스 구하기
			dijkstra1(n, x);

			int posible1 = costs1[g] + gHCost + costs2[h];
			int posible2 = costs1[h] + gHCost + costs2[g];

			if (posible1 == costs1[x] || posible2 == costs1[x])
			{
				cout << x << " ";
			}
		}

		cout << '\n';
	}

	return 0;
}