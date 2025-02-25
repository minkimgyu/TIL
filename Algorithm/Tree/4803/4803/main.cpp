#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int testCount = 0;

	while (1)
	{
		const int maxSize = 500 + 5;
		vector<int> adj[maxSize];
		int p[maxSize];
		bool visit[maxSize];

		fill(p, p + maxSize, 0);
		fill(visit, visit + maxSize, false);

		int result = 0;

		int n, m;
		cin >> n >> m;
		testCount++;

		if (n == 0 && m == 0) break;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == true) continue; // 이미 방문한 경우 순회하지 않음

			queue<int> qu; // queue를 여기서 만들어야함
			qu.push(i);
			visit[i] = true;

			bool haveCycle = false;
			while (qu.empty() == false)
			{
				int front = qu.front(); qu.pop();
				for (int j = 0; j < adj[front].size(); j++)
				{
					int nxt = adj[front][j];
					if (p[front] == nxt) continue; // 부모가 아닌 경우

					if (visit[nxt] == true) // 이전에 방문한 경우
					{
						haveCycle = true;
						break;
					}

					qu.push(nxt);
					visit[nxt] = true;
					p[nxt] = front;
				}

				if (haveCycle == true) break;
			}

			if (haveCycle == false) result++;
		}

		cout << "Case ";
		cout << testCount;
		cout << ": ";

		if (result == 0)
		{
			cout << "No trees.";
		}
		else if (result == 1)
		{
			cout << "There is one tree.";
		}
		else
		{
			cout << "A forest of ";
			cout << result;
			cout << " trees.";
		}

		cout << '\n';
	}

	return 0;
}