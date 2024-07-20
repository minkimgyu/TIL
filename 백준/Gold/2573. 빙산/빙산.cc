#include <iostream>
#include <queue>
#include <map>
using namespace std;

int n, m;
int arr[300][300];

int iceCount = 0;
int loopCount = 0;

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int bfs()
{
	// 처음 얼음이 1개인 경우
	if (iceCount == 1)
	{
		return 0;
	}

	bool** visit = new bool*[300];
	for (int i = 0; i < 300; i++)
	{
		visit[i] = new bool[300]{false, };
	}

	queue<pair<int, int>> queue;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0) continue;

			queue.push({ j, i });
			visit[i][j] = true;
			break;
		}
		if (queue.empty() == false) break;
	}

	int pastIceCount = iceCount;
	int pathCount = 1;

	while (queue.empty() == false)
	{
		pair<int, int> point = queue.front();
		queue.pop();

		for (int i = 0; i < offsetSize; i++)
		{
			int x = point.first + offsets[i].first;
			int y = point.second + offsets[i].second;

			if (x < 0 || x >= m || y < 0 || y >= n) continue;

			int item = arr[y][x];
			if (visit[y][x] == true) continue;

			if (item == 0)
			{
				if (arr[point.second][point.first] <= 0) continue;

				arr[point.second][point.first] -= 1;
				if (arr[point.second][point.first] == 0)
				{
					iceCount -= 1;
				}
			}
			else
			{
				visit[y][x] = true;
				queue.push({ x, y });
				pathCount++;
			}
		}
	}

	for (int i = 0; i < 300; i++)
	{
		delete[] visit[i];
	}
	delete[] visit;

	// 한번에 모든 얼음이 녹은 경우
	if (iceCount == 0 && pathCount == pastIceCount)
	{
		return 0;
	}

	// 분리되고 녹은 경우
	if (iceCount == 0)
	{
		return loopCount;
	}

	// 방문한 개수랑 녹기 전 얼음 개수가 같은 경우
	if (pathCount == pastIceCount)
	{
		loopCount++;
		return bfs();
	}
	else return loopCount;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int item;
			cin >> item;
			arr[i][j] = item;

			if (item == 0) continue;
			iceCount += 1;
		}
	}

	cout << bfs();
	return 0;
}