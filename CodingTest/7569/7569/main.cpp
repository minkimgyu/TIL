#include <iostream>
#include <queue>
<<<<<<< HEAD
using namespace std;

// r, c, h
int n, m, h;

const int maxSize = 100;
int arr[maxSize][maxSize][maxSize]; // h --> n --> m 순으로 들어간다고 생각하면 됨

struct Vector3
{
public:
	int h, r, c;
};

const int offsetSize = 6;
Vector3 offset[offsetSize] =
{
	{0, 0, 1},
	{0, 0, -1},

	{0, 1, 0},
	{0, -1, 0},

	{1, 0, 0},
	{-1, 0, 0},
};

=======
#include <vector>
using namespace std;

int m, n, h;
const int arrSize = 100;
int arr[arrSize][arrSize][arrSize];

struct Vector3
{
	int x, y, z;
};

Vector3 offsets[6]{ 
	{1, 0, 0}, 
	{0, 1, 0}, 
	{-1, 0, 0}, 
	{0, -1, 0},
	{0, 0, 1},
	{0, 0, -1},
};

vector<Vector3> ReturnClosePoints(Vector3 pos)
{
	vector<Vector3> points;
	for (int i = 0; i < 6; i++)
	{
		int x = pos.x + offsets[i].x;
		int y = pos.y + offsets[i].y;
		int z = pos.z + offsets[i].z;

		if (x >= m || x < 0 || y >= n || y < 0 || z >= h || z < 0) continue;

		points.push_back({ x, y, z });
	}

	return points;
}

>>>>>>> origin/main
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

<<<<<<< HEAD
	queue<Vector3> q;
	int leftCount = 0;

	for (int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
=======
	int maxFillCount = m * n * h;
	queue<Vector3> queue;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
>>>>>>> origin/main
		{
			for (int k = 0; k < m; k++)
			{
				int item;
				cin >> item;

				if (item == 1)
				{
<<<<<<< HEAD
					q.push({i, j, k}); // h, r, c
				}
				else if (item == 0)
				{
					leftCount++; // 익지 않은 토마토의 개수를 새준다.
=======
					Vector3 pos;
					pos = { k, j, i };
					queue.push(pos);
				}

				if (item == 1 || item == -1)
				{
					maxFillCount -= 1;
>>>>>>> origin/main
				}

				arr[i][j][k] = item;
			}
		}
	}

<<<<<<< HEAD
	if (leftCount == 0) // 모든 토마토가 익어있는 경우
=======
	int time = 0;
	int fillCount = 0;
	int result = -1;

	if (maxFillCount == fillCount)
>>>>>>> origin/main
	{
		cout << 0;
		return 0;
	}

<<<<<<< HEAD
	while (q.empty() == false)
	{
		Vector3 pos = q.front();
		q.pop();

		int originItem = arr[pos.h][pos.r][pos.c]; // 역순

		for (int i = 0; i < offsetSize; i++)
		{
			Vector3 newPos = { pos.h + offset[i].h, pos.r + offset[i].r, pos.c + offset[i].c };
			if (newPos.r < 0 || newPos.r >= n || newPos.c < 0 || newPos.c >= m || newPos.h < 0 || newPos.h >= h) continue; // 범위 체크

			int item = arr[newPos.h][newPos.r][newPos.c]; // 역순
			if (item >= 1 || item == -1) continue; // 익거나 없는 경우는 건너뛴다.

			leftCount--;
			if (leftCount == 0)
			{
				cout << originItem;
				return 0;
			}

			arr[newPos.h][newPos.r][newPos.c] = originItem + 1; // 익지 않은 토마토가 있는 경우 1을 대입해준다.
			q.push(newPos);
		}
	}

	cout << -1;
=======
	while (queue.empty() == false)
	{
		int queueSize = queue.size();
		for (int i = 0; i < queueSize; i++)
		{
			Vector3 item = queue.front();
			queue.pop();

			vector<Vector3> closePoints = ReturnClosePoints(item);
			for (int j = 0; j < closePoints.size(); j++)
			{
				int x = closePoints[j].x;
				int y = closePoints[j].y;
				int z = closePoints[j].z;

				int arrValue = arr[z][y][x];
				if (arrValue == -1 || arrValue == 1) continue;

				arr[z][y][x] = 1;

				Vector3 closePoint = { x, y, z };
				queue.push(closePoint);
				fillCount++;
			}
		}

		time++;

		if (maxFillCount == fillCount)
		{
			result = time;
			break;
		}
	}

	cout << result;
>>>>>>> origin/main
	return 0;
}