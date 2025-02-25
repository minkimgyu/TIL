#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

const int maxSize = 32000 + 5;
vector<int> adj[maxSize];
int indeg[maxSize];

queue<int> qu;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		// a ���� b�� ���;� �Ѵ�. �׷��Ƿ� ������ a���� b�� ����.
		adj[a].push_back(b); // ���� �߰�
		indeg[b]++; // b�� ���� ���� +1 ���ش�.
	}

	for (int i = 1; i <= n; i++) // <= ����!
	{
		if (indeg[i] == 0) qu.push(i);
	}

	while (qu.empty() == false)
	{
		int front = qu.front(); qu.pop();
		result.push_back(front); // ����� �߰��Ѵ�.

		for (int nxt : adj[front])
		{
			indeg[nxt] -= 1;
			if(indeg[nxt] == 0) qu.push(nxt); // 0�� �Ǹ� �߰�
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		if (i != result.size() - 1) cout << " ";
	}

	return 0;
}