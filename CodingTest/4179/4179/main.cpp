#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int r, c;
char map[1000][1000];

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1},
};

int main()
{
	queue<pair<int, int>> playerQueue;
	queue<pair<int, int>> fireQueue;

	pair<int, int> playerPoint;
	vector<pair<int, int>> firePoints;

	// r = y, c = x;
	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < c; j++)
		{
			char item = line[j];
			if (item == 'J')
			{
				playerQueue.push({ i, j });
			}
			else if(item == 'F')
			{
				fireQueue.push({ i, j });
			}
			map[i][j] = item;
		}
	}

	int exitTime = 0;
	bool canClear = false;

	while (playerQueue.empty() == false)
	{
		int fireQueueSize = fireQueue.size();
		for (int i = 0; i < fireQueueSize; i++)
		{
			pair<int, int> firePoint = fireQueue.front();
			fireQueue.pop();

			for (int j = 0; j < offsetSize; j++)
			{
				int tmpR = firePoint.first + offsets[j].first;
				int tmpC = firePoint.second + offsets[j].second;

				if (tmpR < 0 || tmpC < 0 || tmpR >= r || tmpC >= c) continue;
				if (map[tmpR][tmpC] == '#') continue;
				if (map[tmpR][tmpC] == 'F') continue;

				fireQueue.push({ tmpR, tmpC });
				map[tmpR][tmpC] = 'F';
			}
		}

		int playerQueueSize = playerQueue.size();
		for (int i = 0; i < playerQueueSize; i++)
		{
			pair<int, int> playerPoint = playerQueue.front();
			playerQueue.pop();

			for (int j = 0; j < offsetSize; j++)
			{
				int tmpR = playerPoint.first + offsets[j].first;
				int tmpC = playerPoint.second + offsets[j].second;

				// 가장자리를 넘은 경우
				if (tmpR < 0 || tmpC < 0 || tmpR >= r || tmpC >= c)
				{
					canClear = true;
					break;
				}

				if (map[tmpR][tmpC] == '#') continue;
				if (map[tmpR][tmpC] == 'F') continue;
				if (map[tmpR][tmpC] == 'J') continue;

				playerQueue.push({ tmpR, tmpC });
				map[tmpR][tmpC] = 'J';
			}
			if (canClear == true) break;
		}

		exitTime++;
		if (canClear == true) break;
	}

	if (canClear == false) cout << "IMPOSSIBLE";
	else cout << exitTime;

	return 0;
}