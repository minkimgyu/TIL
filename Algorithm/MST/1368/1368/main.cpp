#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v, e;

bool chk[305];
int digCost[305];

int cnt = 0;
int ans = 0;

// cost, vertex
vector<pair<int, int>> adj[305];

// cost, vertex1, vertex2
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v;
	for (int i = 1; i <= v; i++)
	{
		cin >> digCost[i];
	}

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			int cost;
			cin >> cost;
			adj[i].push_back({ cost, j });
		}
	}

	// v 이전 cost 대입
	for (int j = 1; j <= v; j++)
	{
		adj[v + 1].push_back({ digCost[j], j }); // 임의의 정점에서 1, 2, 3, 4, 5로
		adj[j].push_back({ digCost[j], v + 1 }); // 1, 2, 3, 4, 5에서 임의의 정점으로
	}

	// 첫번째 정점 주변 정점들을 추가해준다.
	chk[1] = true;
	for (int j = 0; j < adj[1].size(); j++)
	{
		pQ.push({ adj[1][j].first, 1, adj[1][j].second });
	}

	while (cnt < v) // 정점이 하나 추가되었기 때문임
	{
		int cost, a, b;
		tie(cost, a, b) = pQ.top(); pQ.pop();

		if (chk[b] == true) continue; // 이미 방문한 정점이면 건너뛰기
		//cout << cost << " " << a << " " << b << " ";

		chk[b] = true;
		cnt++;
		ans += cost;

		for (int j = 0; j < adj[b].size(); j++)
		{
			if (chk[adj[b][j].second] == true) continue; // 이미 방문한 정점이면 건너뛰기
			pQ.push({ adj[b][j].first, b, adj[b][j].second });
		}
	}

	cout << ans;
	return 0;
}