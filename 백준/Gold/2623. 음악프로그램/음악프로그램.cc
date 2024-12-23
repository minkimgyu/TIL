#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int n, m; // 가수 수, PD 수

const int maxSize = 1000 + 5;
vector<int> adj[maxSize];
int indeg[maxSize];

queue<int> qu;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < m; i++)
	{
		int count;
		cin >> count;

		int beforeItem = -1;
		for (int i = 0; i < count; i++)
		{
			int item;
			cin >> item;

			if (beforeItem == -1)
			{
				beforeItem = item;
			}
			else
			{
				adj[beforeItem].push_back(item);
				indeg[item]++;
				beforeItem = item;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0) qu.push(i);
	}

	while (qu.empty() == false)
	{
		int front = qu.front(); qu.pop();
		result.push_back(front);

		for (int nxt : adj[front])
		{
			indeg[nxt] -= 1;
			if(indeg[nxt] == 0) qu.push(nxt);
		}
	}

	if (result.size() != n) // 사이클이 있는 경우
	{
		cout << 0;
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i != result.size() - 1) cout << '\n';
		}
	}

	return 0;
}