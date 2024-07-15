#include <iostream>
#include <queue>
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	int maxFillCount = m * n * h;
	queue<Vector3> queue;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int item;
				cin >> item;

				if (item == 1)
				{
					Vector3 pos;
					pos = { k, j, i };
					queue.push(pos);
				}

				if (item == 1 || item == -1)
				{
					maxFillCount -= 1;
				}

				arr[i][j][k] = item;
			}
		}
	}

	int time = 0;
	int fillCount = 0;
	int result = -1;

	if (maxFillCount == fillCount)
	{
		cout << 0;
		return 0;
	}

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
	return 0;
}