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

		// a 다음 b가 나와야 한다. 그러므로 간선은 a에서 b로 들어간다.
		adj[a].push_back(b); // 간선 추가
		indeg[b]++; // b로 들어가는 간선 +1 해준다.
	}

	for (int i = 1; i <= n; i++) // <= 주의!
	{
		if (indeg[i] == 0) qu.push(i);
	}

	while (qu.empty() == false)
	{
		int front = qu.front(); qu.pop();
		result.push_back(front); // 결과값 추가한다.

		for (int nxt : adj[front])
		{
			indeg[nxt] -= 1;
			if(indeg[nxt] == 0) qu.push(nxt); // 0이 되면 추가
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		if (i != result.size() - 1) cout << " ";
	}

	return 0;
}