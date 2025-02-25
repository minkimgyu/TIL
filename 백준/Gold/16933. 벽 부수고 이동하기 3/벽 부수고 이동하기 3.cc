#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int map[1000][1000];
int visit[2][11][1000][1000]; // 1이 낮, 0이 밤

struct Point
{
public:
	int x, y, breakCount, isDay;
};

const int offsetCount = 4;
pair<int, int> offset[offsetCount] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int ChageDay(int day)
{
	if (day == 1) return 0;
	else if (day == 0) return 1;
}

int bfs()
{
	if (n == 1 && m == 1 && map[0][0] == 0)
	{
		return 1;
	}

	bool isClear = false;
	int minPath = -1;

	queue<Point> queue;
	queue.push({ 0, 0, 0, true});
	visit[1][0][0][0] = 1;

	while (queue.empty() == false)
	{
		Point point = queue.front();
		queue.pop();

		int pastPathCount = visit[point.isDay][point.breakCount][point.y][point.x];

		for (int i = 0; i < offsetCount; i++)
		{
			int newX = point.x + offset[i].first;
			int newY = point.y + offset[i].second;

			if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

			if (newX == m - 1 && newY == n - 1)
			{
				minPath = pastPathCount + 1;
				isClear = true;
				break;
			}

			int changedDay = ChageDay(point.isDay);
			int isWall = map[newY][newX];
			Point newPoint;

			if (point.isDay == 1) // 낮인 경우
			{
				if (isWall == 1 && point.breakCount < k) // 벽인 경우
				{
					newPoint = { newX, newY, point.breakCount + 1, changedDay };

					if (visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] != 0) continue;

					queue.push(newPoint);
					visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] = pastPathCount + 1;
				}
				else if(isWall == 0) // 벽이 아닌 경우
				{
					newPoint = { newX, newY, point.breakCount, changedDay };

					if (visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] != 0) continue;

					queue.push(newPoint);
					visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] = pastPathCount + 1;
				}
			}
			else if (point.isDay == 0) // 밤인 경우 벽을 파괴할 수 없음 낮밤만 바꿔서 제자리에 머문다.
			{
				if (isWall == 0) // 벽이 아닌 경우
				{
					newPoint = { newX, newY, point.breakCount, changedDay };

					if (visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] != 0) continue;

					queue.push(newPoint);
					visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] = pastPathCount + 1;
				}
				else // 벽이 있는 경우
				{
					newPoint = { point.x, point.y, point.breakCount, changedDay };

					if (visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] != 0) continue;

					queue.push(newPoint);
					visit[newPoint.isDay][newPoint.breakCount][newPoint.y][newPoint.x] = pastPathCount + 1;
				}
			}
		}

		if (isClear) break;
	}

	return minPath;
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
		string line;
		getline(cin, line);
		for (int j = 0; j < m; j++)
		{
			map[i][j] = (int)line[j] - 48;
		}
	}

	// 밤인 경우 벽을 만났을 때 정지하는 것이 옳다.
	// 밤이도 벽이 없다면 움직이는게 최단 거리를 구할 수 있는 방법이다.

	cout << bfs();
	return 0;
}