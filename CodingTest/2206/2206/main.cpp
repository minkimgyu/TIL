#include <iostream>
<<<<<<< HEAD
#include <queue>
#include <string>
using namespace std;

int n, m;

const int maxSize = 1001;
int arr[maxSize][maxSize];

const int maxBreakCount = 2;
int visit[maxBreakCount][maxSize][maxSize];

struct Vector3
{
public:
	int breakCount, r, c;
};

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
=======
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

>>>>>>> origin/main
	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);

		for (int j = 0; j < m; j++)
		{
<<<<<<< HEAD
			int item = line[j] - '0';
			arr[i][j] = item;
		}
	}

	// 엣지 케이스
	// n과 m이 1인 경우
	// --> 1를 출력해야함

	if (n == 1 && m == 1)
	{
		if (arr[0][0] == 0)
		{
			cout << 1;
			
		}
		else
		{
			cout << -1;
		}

		return 0;
	}

	bool canClear = false;
	queue<Vector3> q;
	q.push({ 0, 0 });

	while (q.empty() == false)
	{
		Vector3 front = q.front();
		int visitCount = visit[front.breakCount][front.r][front.c];
		q.pop();

		for (int i = 0; i < offsetSize; i++)
		{
			Vector3 point = { front.breakCount, front.r + offsets[i].first, front.c + offsets[i].second };

			if (point.r < 0 || point.r >= n || point.c < 0 || point.c >= m) continue; // 범위를 벗어난 경우
			if (visit[point.breakCount][point.r][point.c] > 0) continue;// 이미 이전에 방문한 경우

			if (arr[point.r][point.c] == 1 && point.breakCount == 0) // 아직 부수지 않았고 벽이 존재하는 경우
			{
				Vector3 breakPoint = { point.breakCount + 1, point.r, point.c }; // breakCount를 1 올려서 진행
				q.push(breakPoint);

				visit[breakPoint.breakCount][breakPoint.r][breakPoint.c] = visitCount + 1;
				continue;
			}
			
			if (arr[point.r][point.c] == 1) continue; // 벽이 있는 경우 건너뛰기

			q.push(point);
			visit[point.breakCount][point.r][point.c] = visitCount + 1;

			if (point.r == n - 1 && point.c == m - 1) // 목적지에 도달한 경우 --> 인덱스라서 -1를 해줘야한다. 꼭 기억하기
			{
				canClear = true;
				cout << visit[point.breakCount][point.r][point.c] + 1; // 1 더해서 리턴
				break;
			}
		}

		if (canClear == true) break;
	}

	if (canClear == false)
	{
		cout << -1;
	}
=======
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
>>>>>>> origin/main

	return 0;
}