#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 100000 + 5;
vector<int> adj[maxSize];
int p[maxSize];

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n - 1; i++) // ������ n - 1��
	{
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> qu;
	qu.push(1);

	while (qu.empty() == false)
	{
		int front = qu.front(); qu.pop();

		for (int i = 0; i < adj[front].size(); i++)
		{
			int nearNode = adj[front][i];
			if (p[front] == nearNode) continue; // ���� ����� ��尡 �θ� ����� ��� continue

			qu.push(nearNode);
			p[nearNode] = front;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		cout << p[i];
		if (i != n) cout << '\n';
	}

	return 0;
}