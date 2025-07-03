#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int maxSize = 1000 + 5;
int pathWeights[maxSize][maxSize]; // 가중치, 이동 노드
int weights[maxSize]; // 가중치

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			pathWeights[i][j] = -1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		weights[i] = 1000000000 + 5;
	}

	for (int i = 0; i < m; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		if (pathWeights[start][end] == -1) pathWeights[start][end] = weight;
		else pathWeights[start][end] = min(pathWeights[start][end], weight); // 중복 방지
	}

	int start, end;
	cin >> start >> end;

	weights[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
	pQ.push({ weights[start], start });

	while (pQ.empty() == false)
	{
		pair<int, int> top = pQ.top(); pQ.pop();

		for (int i = 1; i <= n; i++)
		{
			if (pathWeights[top.second][i] == -1) continue;

			if (weights[i] > top.first + pathWeights[top.second][i])
			{
				weights[i] = top.first + pathWeights[top.second][i];
				pQ.push({ weights[i], i });
			}
		}
	}

	cout << weights[end];
	return 0;
}