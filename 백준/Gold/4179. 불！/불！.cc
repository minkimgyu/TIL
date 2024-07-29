#include <iostream>
#include <string>
#include <queue>
using namespace std;

int r, c;
int map[1000][1000];

struct Point
{
	int x, y, time;
};

queue<Point> playerQueue;
queue<pair<int, int>> fireQueue;
vector<pair<int, int>> offsets =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};

void bfs()
{
	while (playerQueue.empty() == false)
	{
		int fireQueueSize = fireQueue.size();
		for (int i = 0; i < fireQueueSize; i++)
		{
			pair<int, int> front = fireQueue.front();
			fireQueue.pop();

			int offsetSize = offsets.size();
			for (int i = 0; i < offsetSize; i++)
			{
				int x = offsets[i].first + front.first;
				int y = offsets[i].second + front.second;

				if (x < 0 || x >= c || y < 0 || y >= r) continue;
				if (map[y][x] == -2 || map[y][x] == -1) continue;

				map[y][x] = -1;
				fireQueue.push({ x, y });
			}
		}

		int playerQueueSize = playerQueue.size();

		for (int j = 0; j < playerQueueSize; j++)
		{
			Point front = playerQueue.front();
			playerQueue.pop();

			int offsetSize = offsets.size();
			for (int i = 0; i < offsetSize; i++)
			{
				int x = offsets[i].first + front.x;
				int y = offsets[i].second + front.y;
				int time = front.time;

				if (x < 0 || x >= c || y < 0 || y >= r)
				{
					// 게임 클리어
					cout << time;
					return;
				}
				if (map[y][x] != 0) continue;

				int newTime = time + 1;
				map[y][x] = newTime;
				playerQueue.push({ x, y, newTime });
			}
		}
	}

	cout << "IMPOSSIBLE";
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
			char item = line[j];
			if (item == '#')
			{
				map[i][j] = -2;
			}
			else if (item == 'F')
			{
				map[i][j] = -1; // queue에 넣어주기
				fireQueue.push({ j, i });
			}

			else if (item == '.')
			{
				map[i][j] = 0;
			}
			else if (item == 'J')
			{
				map[i][j] = 1; // queue에 넣어주기
				playerQueue.push({ j, i, 1 });
			}
		}
	}

	bfs();

	return 0;
}