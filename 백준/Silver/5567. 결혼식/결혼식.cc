#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 500 + 5;
vector<int> adj[maxSize];
int visit[maxSize];

queue<int> qu;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int m;
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	fill(visit, visit + n + 1, -1);

	qu.push(1);
	visit[1] = 0;

	while (qu.empty() == false)
	{
		int front = qu.front(); qu.pop();
		int visitCount = visit[front];

		for (int i = 0; i < adj[front].size(); i++)
		{
			int closePoint = adj[front][i];
			if (visit[closePoint] > -1) continue;

			qu.push(closePoint);

			int currentVisitCount = visitCount + 1;
			visit[closePoint] = currentVisitCount;

			if(1 <= currentVisitCount && currentVisitCount <= 2) result++;
		}
	}

	cout << result;
	return 0;
}