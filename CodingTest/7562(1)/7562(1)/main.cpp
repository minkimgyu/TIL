#include <iostream>
#include <queue>
using namespace std;

int t;
const int offsetSize = 8;
const int mapSize = 300;

int map[mapSize][mapSize];

// r, c
pair<int, int> offset[offsetSize] =
{
	{2, -1},
	{2, 1},

	{1, -2},
	{1, 2},

	{-2, -1},
	{-2, 1},

	{-1, -2},
	{-1, 2},
};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		bool isClear = false;
		int widthSize, time = 0;
		cin >> widthSize;

		pair<int, int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		queue<pair<int, int>> qu;
		qu.push(start);
		map[start.first][start.second] = 1;

		while(qu.empty() == false)
		{
			pair<int, int> front = qu.front();
			qu.pop();

			for (int k = 0; k < offsetSize; k++)
			{
				pair<int, int> point;

				point.first = front.first + offset[k].first;
				point.second = front.second + offset[k].second;

				if (point.first < 0 || point.second < 0 || point.first >= widthSize || point.second >= widthSize) continue;
				if (map[point.first][point.second] >= 1) continue; // 이미 간 곳을 또 간 경우

				if (point.first == end.first && point.second == end.second)
				{
					time = map[front.first][front.second];
					isClear = true;
					break;
				}

				map[point.first][point.second] = map[front.first][front.second] + 1;
				qu.push(point);
			}

			if (isClear) break;
		}

		for (int l = 0; l < widthSize; l++)
		{
			for (int p = 0; p < widthSize; p++)
			{
				map[l][p] = 0;
			}
		}

		cout << time;
		if (i != t) cout << '\n';
	}

	return 0;
}