#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int v, e;

// ����ġ, ���� ��ȣ
vector<pair<int, int>> adj[10000 + 5];
bool chk[10000 + 5]; // �湮 Ȯ��

int cnt = 0; // ���� ���õ� ������ ����
int ans = 0;

// minHeap ����ġ, ����1, ����2
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}

	chk[1] = true;
	for (int i = 0; i < adj[1].size(); i++)
	{
		pQ.push({ adj[1][i].first, 1, adj[1][i].second }); // ���� 1���� ����
	}

	while (cnt < v - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = pQ.top(); pQ.pop();
		if (chk[b] == true) continue;

		chk[b] = true;
		cnt++;
		ans += cost;

		for (int i = 0; i < adj[b].size(); i++)
		{
			if (adj[b][i].second == true) continue;
			pQ.push({ adj[b][i].first, b, adj[b][i].second }); // ���� 1���� ����
		}
	}

	cout << ans;

	return 0;
}