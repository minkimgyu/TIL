#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int peopleCount = 101; 
bool link[peopleCount][peopleCount];

// 엣지 케이스 : 인덱스가 1부터 시작하므로 peopleCount가 101 이어야함

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		link[start][end] = true;
		link[end][start] = true;
	}

	int result = 1000000000;
	int index = -1;

	for (int i = n; i >= 1; i--)
	{
		map<int, int> visit;
		queue<pair<int, int>> q;

		q.push({ i, 1 });
		visit[i] = 1;

		while (q.empty() == false)
		{
			pair<int, int> front = q.front();
			q.pop();

			int peopleIndex = front.first;
			int passCount = front.second;

			for (int j = 1; j <= n; j++)
			{
				bool isConnect = link[peopleIndex][j];
				if (isConnect == false) continue; // 커넥션이 없으면 건너뛰기
				if (visit[j] > 0) continue; // 이미 방문했다면 건너뛰기

				q.push({ j, passCount + 1 });
				visit[j] = passCount + 1;
			}
		}

		int sum = 0;

		for (int k = 1; k <= n; k++)
		{
			if (i == k) continue; // 자기 자신 빼주기

			int passCount = visit[k] - 1;
			sum += passCount;
		}

		if (result >= sum)
		{
			result = sum;
			index = i;
		}
	}

	cout << index;
	return 0;
}