#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
const int maxN = 100;
vector<vector<int>> connections(maxN);

int bfs(int personIndex)
{
	bool visit[maxN] = {false, };

	queue<pair<int, int>> queue;
	queue.push({ personIndex, 0 });
	visit[personIndex] = true;

	int sum = 0;

	while (queue.empty() == false)
	{
		pair<int, int> front = queue.front();
		queue.pop();

		sum += front.second;

		vector<int> connection = connections[front.first];
		for (int i = 0; i < connection.size(); i++)
		{
			int index = connection[i];
			if (visit[index] == true) continue;

			visit[index] = true;
			queue.push({ index, front.second + 1 });
		}
	}

	return sum;
}

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
		connections[a - 1].push_back(b - 1);
		connections[b - 1].push_back(a - 1);
	}

	int min = 5001;
	int minIndex = -1;

	vector<int> results;
	for (int i = n - 1; i >= 0; i--)
	{
		int result = bfs(i);
		if (min >= result)
		{
			min = result;
			minIndex = i;
		}
	}

	cout << minIndex + 1;

	return 0;
}