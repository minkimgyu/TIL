#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
const int maxSize = 105;
char map[maxSize][maxSize];
char rgMap[maxSize][maxSize];

const int offsetSize = 4;
pair<int, int> offsets[4] =
{
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

int bfs(char map[maxSize][maxSize])
{
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != 'R' && map[i][j] != 'G' && map[i][j] != 'B') continue;

			count += 1;
			char currentChar = map[i][j];

			queue<pair<int, int>> qu;
			map[i][j] = 'C';
			qu.push({ i, j });

			while (qu.empty() == false)
			{
				pair<int, int> front = qu.front();
				qu.pop();

				for (int k = 0; k < offsetSize; k++)
				{
					pair<int, int> point;
					point.first = front.first + offsets[k].first;
					point.second = front.second + offsets[k].second;

					if (point.first < 0 || point.second < 0 || point.first >= n || point.second >= n) continue;
					if (currentChar == map[point.first][point.second])
					{
						map[point.first][point.second] = 'C';
						qu.push(point);
					}
				}
			}
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < n; j++)
		{
			map[i][j] = line[j];
			if (line[j] == 'G') rgMap[i][j] = 'R';
			else rgMap[i][j] = line[j];
		}
	}

	cout << bfs(map) << '\n';
	cout << bfs(rgMap);

	return 0;
}