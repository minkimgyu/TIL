#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n, m, p;
int s[9];
int map[1000][1000];

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

const int maxP = 9;
queue<pair<int, int>> queues[maxP];

int castleCount[maxP];

void bfs()
{
	while (1)
	{
		for (int i = 0; i < p; i++)
		{
			for (int z = 0; z < s[i]; z++)
			{
				int loopCount = queues[i].size();
				if (loopCount == 0) break;

				for (int j = 0; j < loopCount; j++)
				{
					if (queues[i].empty() == true) break;

					pair<int, int> point = queues[i].front();
					queues[i].pop();

					for (int k = 0; k < offsetSize; k++)
					{
						int x = point.first + offsets[k].first;
						int y = point.second + offsets[k].second;

						if (x < 0 || x >= m || y < 0 || y >= n) continue;
						if (map[y][x] != 0) continue;

						castleCount[i] += 1;
						queues[i].push({ x, y });
						map[y][x] = i + 1;
					}

				}
			}
		}

		bool canClear = true;
		for (int i = 0; i < p; i++)
		{
			if (queues[i].empty() == false)
			{
				canClear = false;
			}
		}

		if (canClear) break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> p;
	for (int i = 0; i < p; i++)
	{
		cin >> s[i];
	}
	cin.ignore();

	// # 35
	// . 46

	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < m; j++)
		{
			int item = (int)line[j] - 48;

			if (item == -13)
			{
				map[i][j] = -1; // 장애물
			}
			else if (item == -2)
			{
				map[i][j] = 0; // 이동 가능 구역
			}
			else
			{
				// 이런 식으로 queue에 미리 넣어놓는다.
				castleCount[item - 1] += 1;
				queues[item - 1].push({ j, i });
				map[i][j] = item; // 이동 가능 구역
			}
		}
	}

	bfs();

	for (int i = 0; i < p; i++)
	{
		cout << castleCount[i];
		if(i != p - 1) cout << " ";
	}

	return 0;
}