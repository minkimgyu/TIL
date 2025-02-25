#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 1000 + 5;
vector<int> adj[maxSize];

queue<int> qu;
bool visit[maxSize];
int result = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// 반복해서 갯수 구하기
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == true) continue;

		qu.push(i);
		visit[i] = true;
		result++;

		while (qu.empty() == false)
		{
			int front = qu.front(); qu.pop();
			
			for (int j = 0; j < adj[front].size(); j++)
			{
				int point = adj[front][j];
				if (visit[point] == true) continue;

				qu.push(point);
				visit[point] = true;
			}
		}
	}

	cout << result;
	return 0;
}