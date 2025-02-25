
// ��� ������ �� ������ ���� �� �Ÿ��� ���ϴ� �� ���� ������?
// --> �� ��� O(n(n + e))�� �ð� �ʰ� 

// ������ �������� ���� �ָ� ������ ������ ���Ѵ�.
// ������ �������� ���� �ָ� ������ ������ ���̸� ���Ѵ�.

// --> �� ������ ���ؼ� Ʈ���� ������ ���Ѵ�.

#include <iostream>
#include <vector>
using namespace std;

const int pointSize = 100005;

bool visit[pointSize];
vector<pair<int, int>> connections[pointSize];
int n;

int maxDistance = 0;
int maxPoint = 0;

// 1 -(2)- 3
//         |
//		  (3)
//         |
// 2 -(4)- 4
//         |
//        (6)
//         |
//         5

void dfs(int point, int storedDistance)
{
	vector<pair<int, int>> connection = connections[point];
	for (int i = 0; i < connection.size(); i++)
	{
		if (visit[connection[i].first] == true) continue;
		visit[connection[i].first] = true;

		int currentDistance = storedDistance;
		currentDistance += connection[i].second;

		if (currentDistance > maxDistance)
		{
			maxPoint = connection[i].first;
			maxDistance = currentDistance;
		}

		dfs(connection[i].first, currentDistance);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int start;
		cin >> start; // ������ ���� ���� ���·� �Է��� ���� �� ����

		while (1)
		{
			int point;
			int value;
			cin >> point;
			if (point == -1) break;

			cin >> value;
			connections[start].push_back({point, value});
		}
	}

	visit[1] = true;
	dfs(1, 0);

	for (int i = 1; i < pointSize; i++)
	{
		visit[i] = false;
	}

	visit[maxPoint] = true;
	dfs(maxPoint, 0);

	cout << maxDistance;
	return 0;
}