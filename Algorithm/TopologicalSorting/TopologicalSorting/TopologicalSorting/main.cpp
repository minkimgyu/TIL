#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 10;
vector<int> adj[maxSize]; // ������ ���� ����
int indeg[maxSize]; // indegree ����

int n;

queue<int> qu;
vector<int> result;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	// �켱 indeg�� 0�� ���� queue�� �־��ش�.
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0) qu.push(i);
	}

	// while�� �ȿ��� ��� ������ ������ش�. 
	// --> while���� �ִ� ���� ������ŭ ���ư��� ������ for���� �ִ� ���� ���� ��ŭ�� ���ư��� ������ �ð����⵵�� O(V + E)��.
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

	if (result.size() != n) cout << "����Ŭ�� ������";
	else 
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
			if (i != result.size() - 1) cout << " ";
		}
	}

	return 0;
}