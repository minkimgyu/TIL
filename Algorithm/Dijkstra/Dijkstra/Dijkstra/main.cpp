#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int currentSize = 6;
const int offset = 5;

const int maxSize = currentSize + offset;

// first는 인덱스, second는 값
vector<pair<int, int>> adj[maxSize];
bool visit[maxSize]; // 확정 목적으로 존재

int result[maxSize];

struct Compare
{
	bool operator()(pair<int, int> a, pair<int, int> b) const
	{
		if (a.second == b.second) return a.first > b.first;
		return a.second > b.second;
	}
};

// first는 인덱스, second는 값
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(result, result + maxSize, 2100000000);

	adj[1].push_back({ 2, 3 });
	adj[1].push_back({ 3, 2 });
	adj[1].push_back({ 4, 5 });

	adj[2].push_back({ 3, 2 });
	adj[2].push_back({ 5, 8 });

	adj[3].push_back({ 4, 2 });

	adj[4].push_back({ 5, 6 });

	adj[5].push_back({ 6, 1 });


	result[1] = 0;
	pQ.push({ 1, 0 });

	while (pQ.empty() == false)
	{
		pair<int, int> front = pQ.top(); pQ.pop();
		visit[front.first] = true;

		int frontDistance = result[front.first];

		for (int i = 0; i < adj[front.first].size(); i++)
		{
			pair<int, int> near = adj[front.first][i];
			if (visit[near.first] == true) continue;

			int distance = frontDistance + near.second;
			if (result[near.first] > distance)
			{
				result[near.first] = distance;
				pQ.push({ near.first, distance });
			}
		}
	}

	for (int i = 1; i <= currentSize; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}