#include <iostream>
#include <string>
#include <deque>
using namespace std;

const int maxSize = 500 + 5;
char mapArr[maxSize][maxSize];
int costArr[maxSize][maxSize];

pair<int, int> offset[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int h, w;

bool CloseToWall(pair<int, int> pos)
{
	bool isClose = false;

	for (int i = 0; i < 4; i++)
	{
		pair<int, int> nearPos = { pos.first + offset[i].first, pos.second + offset[i].second };
		if (mapArr[nearPos.first][nearPos.second] == '#')
		{
			isClose = true;
			break;
		}
	}

	return isClose;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;

	pair<int, int> start;
	pair<int, int> end;

	for (int i = 0; i < h; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < w; j++)
		{
			mapArr[i][j] = s[j];
			costArr[i][j] = maxSize * maxSize;

			if (mapArr[i][j] == 'S') start = { i, j };
			if (mapArr[i][j] == 'E') end = { i, j };
		}
	}

	deque<pair<int, pair<int, int>>> dq;

	dq.push_back({0, start });
	costArr[start.first][start.second] = 0;

	while (dq.empty() == false)
	{
		pair<int, pair<int, int>> front = dq.front(); dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nearPos = { front.second.first + offset[i].first, front.second.second + offset[i].second };
			if (mapArr[nearPos.first][nearPos.second] == '#') continue;

			if (CloseToWall(front.second) == true && CloseToWall(nearPos) == true) // 인접한 면에서 인접한 면으로 이동
			{
				if (costArr[nearPos.first][nearPos.second] > front.first)
				{
					dq.push_front({ front.first, nearPos });
					costArr[nearPos.first][nearPos.second] = front.first;
				}
			}
			else
			{
				if (costArr[nearPos.first][nearPos.second] > front.first + 1)
				{
					dq.push_back({ front.first + 1, nearPos });
					costArr[nearPos.first][nearPos.second] = front.first + 1;
				}
			}
		}
	}

	cout << costArr[end.first][end.second];
	return 0;
}