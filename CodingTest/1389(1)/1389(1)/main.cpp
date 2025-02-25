#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> connections[101];
int n, m;

int result = 5001; // 범위 조심!
int minIndex = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
		connections[end].push_back(start);
	}

	for (int i = 1; i <= n; i++)
	{
		const int maxVisit = 100;
		int visit[maxVisit];
		for (int j = 1; j <= maxVisit; j++) visit[j] = 0;

		int k = 0;
		queue<int> peopleQueue;
		peopleQueue.push(i);

		while (peopleQueue.empty() == false)
		{
			int top = peopleQueue.front();
			peopleQueue.pop();

			int passedTime = visit[top];

			int connectionsSize = connections[top].size();
			for (int j = 0; j < connectionsSize; j++)
			{
				int near = connections[top][j];

				if (near == i) continue; // 다시 돌아서 자신에게 온다면 continue;
				if (visit[near] > 0) continue;

				peopleQueue.push(near);
				visit[near] = passedTime + 1;
				k += passedTime + 1;
			}
		}

		if (k < result)
		{
			result = k;
			minIndex = i;
		}
	}

	cout << minIndex;
	return 0;
}