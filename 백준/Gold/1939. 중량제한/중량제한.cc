#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxSize = 10000 + 5;
vector<pair<int, int>> connections[maxSize]; // 도착지, 가중치
bool visit[maxSize];
int maxCost = 0;

int startIdx, endIdx;

bool bfs(int currentCost)
{
	queue<int> q;
	q.push(startIdx);
	visit[startIdx] = true;

	while (q.empty() == false)
	{
		int front = q.front(); q.pop();
		if (front == endIdx) return true;

		for (int i = 0; i < connections[front].size(); i++)
		{
			int nxtIdx = connections[front][i].first;
			int nxtCost = connections[front][i].second;

			if (visit[nxtIdx] == false && currentCost <= nxtCost)
			{
				visit[nxtIdx] = true;
				q.push(nxtIdx);
			}
		}
	}

	return false;
}

int binary_search()
{
	int left = 1;
	int right = maxCost;

	while (left <= right)
	{
		for (int i = 0; i < maxSize; i++)
		{
			visit[i] = false;
		}

		int mid = (left + right) / 2;
		bool canPass = bfs(mid);

		if (canPass == true) left = mid + 1; // 통과하면 더 늘려줌
		else right = mid - 1;  // 통과하지 못하면 더 줄여줌
	}

	return right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;


	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		connections[a].push_back({ b, c });
		connections[b].push_back({ a, c });

		maxCost = max(maxCost, c);
	}

	cin >> startIdx >> endIdx;
	cout << binary_search();
	return 0;
}