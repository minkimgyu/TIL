#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;

const int maxMSize = 100 + 5;
vector<pair<int, int>> connections[maxMSize];

const int maxNSize = 100 + 5;
int indegree[maxNSize];
bool haveIndegree[maxNSize];

int results[maxNSize][maxNSize];
bool visits[maxNSize];

priority_queue<int, vector<int>, greater<int>> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end, count;
		cin >> start >> end >> count;
		connections[end].push_back({ start, count});

		indegree[start]++;
		haveIndegree[start] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0 && visits[i] == false)
		{
			pQ.push(i);
			visits[i] = true;
		}
	}

	while (pQ.empty() == false)
	{
		int top = pQ.top(); pQ.pop();

		for (int i = 0; i < connections[top].size(); i++)
		{
			indegree[connections[top][i].first]--;

			if (haveIndegree[top] == false)
			{
				results[connections[top][i].first][top] += connections[top][i].second;
			}
			else
			{
				for (int j = 1; j <= n; j++)
				{
					results[connections[top][i].first][j] += (results[top][j]) * connections[top][i].second;
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0 && visits[i] == false)
			{
				pQ.push(i);
				visits[i] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (results[n][i] != 0)
		{
			cout << i << " " << results[n][i];
			cout << '\n';
		}
	}

	return 0;
}