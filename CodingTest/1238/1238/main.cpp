#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> map[1001];
int shortPath

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	int* shortPath = new int[n] {-1, };
	int* targetToOrigin = new int[n];

	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		map[start].push_back({ end, cost });
	}

	for (int i = 1; i <= n; i++)
	{
		vector<pair<int, int>> routes = map[i];
		for (int i = 0; i < routes.size(); i++)
		{
			pq.push(routes[i]);
		}

		
	}

	delete[] shortPath;
	delete[] targetToOrigin;

	return 0;
}