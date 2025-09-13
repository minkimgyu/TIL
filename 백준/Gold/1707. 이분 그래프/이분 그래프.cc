#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 20000 + 5;
vector<int> connections[maxSize];
int visits[maxSize]; // 1, 2로 칠하기

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;
	
	while (k--)
	{
		int v, e;
		cin >> v >> e;

		// 초기화
		for (int i = 1; i < maxSize; i++)
		{
			connections[i].clear();
			visits[i] = 0;
		}

		for (int i = 0; i < e; i++)
		{
			int a, b;
			cin >> a >> b;

			connections[a].push_back(b);
			connections[b].push_back(a);
		}

		bool canClear = true;

		for (int z = 1; z <= v; z++)
		{
			if (visits[z] != 0) continue; // 이미 할당된 경우 건너뛰기

			// bfs로 인접한 모든 노드를 색칠할 수 있다.
			// 
			// 어차피 그래프 끼리 구분된 경우이기 때문에
			// 따라서 첫번째 노드 색은 1로 칠하든 -1로 칠하든 상관 없음
			queue<int> q;
			q.push(z);
			visits[z] = 1; // 1로 할당

			while (q.empty() == false)
			{
				int front = q.front(); q.pop();

				for (int i = 0; i < connections[front].size(); i++)
				{
					int nxtIdx = connections[front][i];

					if (visits[nxtIdx] == 0) // 방문하지 않은 경우
					{
						visits[nxtIdx] = visits[front] * -1; // 색 바꿔서 넣기
						q.push(nxtIdx); // 큐에 추가
					}
					else if (visits[nxtIdx] == visits[front]) // 같은 경우 -> 이분 그래프 불가능
					{
						canClear = false;
						break;
					}
				}

				if (canClear == false) break;
			}
		}

		if (canClear == false) cout << "NO";
		else cout << "YES";

		if(k != 0) cout << '\n';
	}

	return 0;
}