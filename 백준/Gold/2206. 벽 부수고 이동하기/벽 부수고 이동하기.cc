#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Point
{
public:
	int x, y, breakCount;
};

int n, m;
int map[1000][1000];
bool visit[2][1000][1000];

const int offsetCount = 4;
pair<int, int> offset[offsetCount] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

vector<Point> ReturnClosePoint(Point point)
{
	vector<Point> points;
	for (int i = 0; i < offsetCount; i++)
	{
		int x = point.x + offset[i].first;
		int y = point.y + offset[i].second;

		if (x < 0 || x >= m || y < 0 || y >= n) continue;

		points.push_back({x, y, point.breakCount});
	}

	return points;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<Point> queue;

	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);

		for (int j = 0; j < m; j++)
		{
			int item = (int)line[j];
			map[i][j] = item - 48;
		}
	}

	if (n == 1 && m == 1 && map[n - 1][m - 1] == 0)
	{
		cout << 1;
		return 0;
	}

	queue.push({ 0, 0, 0 });
	visit[0][0][0] = true;

	int length = 1;
	bool canClear = false;

	while (queue.empty() == false)
	{
		int queueSize = queue.size();
		for (int j = 0; j < queueSize; j++)
		{
			Point point = queue.front();
			queue.pop();

			vector<Point> closePoints = ReturnClosePoint(point);
			for (int i = 0; i < closePoints.size(); i++)
			{
				Point closePoint = closePoints[i];
				int item = map[closePoint.y][closePoint.x];

				if (closePoint.x == m - 1 && closePoint.y == n - 1)
				{
					canClear = true;
					break;
				}

				if (visit[closePoint.breakCount][closePoint.y][closePoint.x] == true) continue;

				if (item == 0)
				{
					queue.push(closePoint);
					visit[closePoint.breakCount][closePoint.y][closePoint.x] = true;
				}

				if (item == 1 && closePoint.breakCount == 0)
				{
					closePoint.breakCount += 1;

					queue.push(closePoint);
					visit[closePoint.breakCount][closePoint.y][closePoint.x] = true;
				}
			}

			if (canClear == true) break;
		}

		length++;
		if (canClear == true) break;
	}

	if (canClear == false) cout << -1;
	else cout << length;

	return 0;
}