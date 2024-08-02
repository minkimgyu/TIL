#include <iostream>
#include <string>
#include <queue>
using namespace std;

int t, h, w;
string keys;

queue<pair<int, int>> entryQueue;

const int arrSize = 100;
char map[arrSize][arrSize];
int visit[arrSize][arrSize];

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1},
};

int documentCount = 0;

bool HaveKey(char item)
{
	int keySize = keys.size();
	for (int i = 0; i < keySize; i++)
	{
		int keyOffset = (int)keys[i] - 97;
		int itemOffset = (int)item - 65;

		if (keyOffset == itemOffset)
		{
			return true;
		}
	}

	return false;
}

void AddEntryPoint(int i, int j)
{
	char item = map[i][j];

	if (item == '.')
	{
		entryQueue.push({ j, i });
	}
	if (item == '$')
	{
		map[i][j] = '.';
		documentCount++;
		entryQueue.push({ j, i });
	}
	else if ((int)item >= 65 && (int)item < 65 + 26)
	{
		bool nowHave = HaveKey(item);
		if (nowHave == true)
		{
			entryQueue.push({ j, i });
		}
	}
	else if ((int)item >= 97 && (int)item < 97 + 26)
	{
		// 해당 위치가 키의 위치인 경우
		entryQueue.push({ j, i });

		bool haveKey = false;
		int keySize = keys.size();
		for (int i = 0; i < keySize; i++)
		{
			if (keys[i] == item)
			{
				haveKey = true;
				break;
			}
		}

		if (haveKey == false)
		{
			keys.push_back(item);
		}
	}
}

int bfs()
{
	int visitLoopCount = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
			{
				AddEntryPoint(i, j);
			}
		}
	}

	while (entryQueue.empty() == false)
	{
		visitLoopCount++;
		queue<pair<int, int>> visitQueue;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
				{
					AddEntryPoint(i, j);
				}
			}
		}

		int entryQueueSize = entryQueue.size();
		for (int k = 0; k < entryQueueSize; k++)
		{
			pair<int, int> startPoint = entryQueue.front();
			entryQueue.pop();

			if (visit[startPoint.second][startPoint.first] == visitLoopCount) continue;

			visitQueue.push(startPoint);
			visit[startPoint.second][startPoint.first] = visitLoopCount;
		}

		while (visitQueue.empty() == false)
		{
			pair<int, int> point = visitQueue.front();
			visitQueue.pop();

			for (int i = 0; i < offsetSize; i++)
			{
				int x = point.first + offsets[i].first;
				int y = point.second + offsets[i].second;

				if (x < 0 || x >= w || y < 0 || y >= h) continue;

				char item = map[y][x];

				if (map[y][x] == '*') continue;
				if ((int)item >= 65 && (int)item < 65 + 26) // 문인 경우
				{
					bool nowHave = HaveKey(item);
					if (nowHave == false) continue;
				}
				if (visit[y][x] == visitLoopCount) continue;

				if (item == '$')
				{
					map[y][x] = '.';
					documentCount++;
				}

				if ((int)item >= 97 && (int)item < 97 + 26) // 열쇠인 경우
				{
					bool haveKey = false;
					int keySize = keys.size();
					for (int i = 0; i < keySize; i++)
					{
						if (keys[i] == item)
						{
							haveKey = true;
							break;
						}
					}

					if (haveKey == false)
					{
						entryQueue.push({ x, y });
						keys.push_back(item);
					}
				}

				visitQueue.push({ x, y });
				visit[y][x] = visitLoopCount;
			}
		}
	}

	return documentCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	cin.ignore();

	for (int j = 0; j < t; j++)
	{
		keys = "";
		queue<pair<int, int>> newEntryQueue;
		entryQueue = newEntryQueue;

		cin >> h >> w;
		cin.ignore();

		for (int i = 0; i < h; i++)
		{
			string line;
			getline(cin, line);
			for (int j = 0; j < w; j++)
			{
				map[i][j] = line[j];
				visit[i][j] = 0;
			}
		}

		string newKeys;
		getline(cin, newKeys);
		if (newKeys[0] != '0')
		{
			for (int i = 0; i < newKeys.size(); i++)
			{
				keys.push_back(newKeys[i]);
			}
		}

		cout << bfs();
		documentCount = 0;
		if (j != t - 1) cout << '\n';
	}

	return 0;
}