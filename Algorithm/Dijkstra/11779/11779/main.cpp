#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;

const int maxSize = 1000 + 5;

// ���, ����

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

		if (result[front.second] != cost) continue; 
		// �ٸ��ٸ� ������ ������ ���� �ٸ��ٴ� �Ҹ���
		// ������ ������ ���� ���� Ȯ���� �Ǿ� �켱���� ť�� �� �� ����
		// ť���� ���� ù��° ���� Ȯ���� ����
		// ���Ŀ��� �ٸ� ���� ���ð���

		for (int i = 0; i < adj[front.second].size(); i++)
		{
			int nextIndex = adj[front.second][i].second;

			int nextCost = cost + adj[front.second][i].first;
			if (result[nextIndex] <= nextCost) continue; // ��� �迭���� nextCost���� ū ��쿡�� ����

			pass[nextIndex] = front.second; // ���� �ε��� ���� �־��ش�.
			result[nextIndex] = nextCost; // nextCost ���� �־��ش�.
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