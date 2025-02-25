#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

const int maxSize = 1000 + 5;

// 비용, 방향

int result[maxSize];
int pass[maxSize];
vector<pair<int, int>> adj[maxSize];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;

int main()
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start].push_back({ cost, end });
	}

	int start, end;
	cin >> start >> end;

	fill(result, result + maxSize, 2100000000);

	pQ.push({ 0, start });
	result[start] = 0;

	while (pQ.empty() == false)
	{
		pair<int, int> front = pQ.top(); pQ.pop();
		int cost = front.first;

		if (result[front.second] != cost) continue; // 다르다면 이전에 대입한 값과 다르다는 소리임

		for (int i = 0; i < adj[front.second].size(); i++)
		{
			int nextIndex = adj[front.second][i].second;

			int nextCost = cost + adj[front.second][i].first;
			if (result[nextIndex] <= nextCost) continue; // 결과 배열값이 nextCost보다 큰 경우에만 진행

			pass[nextIndex] = front.second; // 이전 인덱스 값을 넣어준다.
			result[nextIndex] = nextCost; // nextCost 값을 넣어준다.
			pQ.push({ nextCost, nextIndex });
		}
	}

	cout << result[end] << '\n';

	vector<int> route;
	int currentIndex = end;
	while (currentIndex != 0)
	{
		route.push_back(currentIndex);
		currentIndex = pass[currentIndex];
	}

	cout << route.size() << '\n';

	for (int i = route.size() - 1; i > -1; i--)
	{
		cout << route[i];
		if(i != 0) cout << " ";
	}
}