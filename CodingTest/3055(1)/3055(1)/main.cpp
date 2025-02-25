#include <iostream>
#include <queue>
#include <string>
using namespace std;

int r, c;
int map[50][50];

const int offsetCount = 4;
pair<int, int> offsets[offsetCount] =
{
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1},
};

queue<pair<int, int>> playerQueue;
queue<pair<int, int>> waterQueue;

// 돌 = -1
// 물 = -2
// 비버 굴 = -3
// 비버 = 1

void bfs()
{
	int time = 0;
	bool isClear = false;

	while (playerQueue.empty() == false)
	{
		int waterQueueSize = waterQueue.size();
		for (int i = 0; i < waterQueueSize; i++)
		{
			pair<int, int> front = waterQueue.front();
			waterQueue.pop();

			for (int j = 0; j < offsetCount; j++)
			{
				int x = front.first + offsets[j].first;
				int y = front.second + offsets[j].second;

				if (x < 0 || x >= c || y < 0 || y >= r) continue;
				if (map[y][x] == -3) continue;
				if (map[y][x] == -1) continue;
				if (map[y][x] == -2) continue;

				map[y][x] = -2;
				waterQueue.push({ x, y });
			}
		}

		int playerQueueSize = playerQueue.size();
		for (int i = 0; i < playerQueueSize; i++)
		{
			pair<int, int> front = playerQueue.front();
			playerQueue.pop();

			for (int j = 0; j < offsetCount; j++)
			{
				int x = front.first + offsets[j].first;
				int y = front.second + offsets[j].second;

				if (x < 0 || x >= c || y < 0 || y >= r) continue;
				if (map[y][x] == -2) continue;
				if (map[y][x] == -1) continue;
				if (map[y][x] == 1) continue;

				if (map[y][x] == -3)
				{
					isClear = true;
					break;
				}

				map[y][x] = 1;
				playerQueue.push({ x, y });
			}

			if (isClear) break;
		}

		time++;
		if (isClear) break;
	}

	if (isClear == true) cout << time;
	else cout << "KAKTUS";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		string line;
		getline(cin, line);

		for (int j = 0; j < c; j++)
		{
			if (line[j] == 'D')
			{
				map[i][j] = -3;
			}
			else if (line[j] == 'S')
			{
				map[i][j] = 1;
				playerQueue.push({ j, i });
			}
			else if (line[j] == '.')
			{
				map[i][j] = 0;
			}
			else if (line[j] == 'X')
			{
				map[i][j] = -1;
			}
			else if (line[j] == '*')
			{
				map[i][j] = -2;
				waterQueue.push({ j, i });
			}
		}
	}

	bfs();

	return 0;
}