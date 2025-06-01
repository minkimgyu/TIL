#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxNSize = 32000 + 5;
const int maxMSize = 100000 + 5;

int indegree[maxNSize];
bool visit[maxNSize];
vector<int> connections[maxMSize];

priority_queue<int, vector<int>, greater<int>> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
		indegree[end]++;
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0 && visit[i] == false)
		{
			pQ.push(i);
			visit[i] = true;
		}
	}

	while (pQ.empty() == false)
	{
		int top = pQ.top(); pQ.pop();
		cout << top << " ";

		for (int i = 0; i < connections[top].size(); i++)
		{
			indegree[connections[top][i]]--;

			if (indegree[connections[top][i]] == 0 && visit[connections[top][i]] == false)
			{
				pQ.push(connections[top][i]);
				visit[connections[top][i]] = true;
			}
		}
	}

	return 0;
}