#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int n, m, k;
int map[1000][1000];
bool visit[11][1000][1000];

struct Point
{
public:
	int x, y, breakCount;
};

const int offsetCount = 4;
pair<int, int> offsets[offsetCount] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<Point> ReturnClosePoints(Point point)
{
	vector<Point> points;
	for (int i = 0; i < offsetCount; i++)
	{
		int x = point.x + offsets[i].first;
		int y = point.y + offsets[i].second;

		if (x < 0 || x >= m || y < 0 || y >= n) continue;

		points.push_back({ x, y, point.breakCount });
	}

	return points;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < m; j++)
		{
			map[i][j] = (int)str[j] - 48;
		}
	}

	if (n == 1 && m == 1 && map[0][0] == 0)
	{
		cout << 1;
		return 0;
	}

	queue<Point> queue;
	queue.push({ 0, 0, 0 });
	visit[0][0][0] = true;

	int pathCount = 1;
	bool isClear = false;

	while (queue.empty() == false)
	{
		int queueSize = queue.size();
		for (int i = 0; i < queueSize; i++)
		{
			Point point = queue.front();
			queue.pop();

			vector<Point> points = ReturnClosePoints(point);
			for (int j = 0; j < points.size(); j++)
			{
				int x = points[j].x;
				int y = points[j].y;
				int breakCount = points[j].breakCount;

				if (visit[breakCount][y][x] == true) continue;

				if (y == n - 1 && x == m - 1)
				{
					isClear = true;
					break;
				}

				int item = map[y][x];
				if (item == 1 && breakCount < k)
				{
					queue.push({ x, y, breakCount + 1 });
					visit[breakCount][y][x] = true;
				}
				else if(item == 0)
				{
					queue.push({ x, y, breakCount });
					visit[breakCount][y][x] = true;
				}
			}

			if (isClear == true) break;
		}

		pathCount++;
		if (isClear == true) break;
	}


	if (isClear == true) cout << pathCount;
	else cout << -1;

	return 0;
}