#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;

const int maxSize = 8 + 5;
int map[maxSize][maxSize];
int visit[maxSize][maxSize];

int result = 0;
int hideCount = 0;

int p[maxSize];
vector<pair<int, pair<int, int>>> cctvPoints; // type, pos

bool nowWall(pair<int, int> point)
{
	return map[point.first][point.second] == 6; // 6은 벽
}

bool outOfRange(pair<int, int> point)
{
	return point.first < 0 || point.second < 0 || point.first > r - 1 || point.second > c - 1;
}

pair<int, int> directions[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0},  }; // right, down, left, up, 

void checkMap(pair<int, int> point, int index)
{
	if (outOfRange(point) == true || nowWall(point) == true) return; // 범위를 벗어나면 끝

	if (visit[point.first][point.second] == 0)
	{
		visit[point.first][point.second] = 1; // 방문 처리 하기
		hideCount -= 1;
	}

	point = { point.first + directions[index].first, point.second + directions[index].second };
	checkMap(point, index);
}

void useCamera(int rotate, int type, pair<int, int> point)
{
	switch (type)
	{
		case 1:
			switch (rotate)
			{
				case 0: 
					checkMap(point, 0); // right
					break;
				case 1: 
					checkMap(point, 1); // down
					break;
				case 2: 
					checkMap(point, 2); // left
					break;
				case 3: 
					checkMap(point, 3); // up
					break;
			}
			break;

		case 2:
			switch (rotate)
			{
			case 0: 
				checkMap(point, 0); // right
				checkMap(point, 2); // left
				break;
			case 1: 
				checkMap(point, 1); // down
				checkMap(point, 3); // up
				break;
			case 2: 
				checkMap(point, 0); // right
				checkMap(point, 2); // left
				break;
			case 3: 
				checkMap(point, 1); // down
				checkMap(point, 3); // up
				break;
			}
			break;

		case 3:
			switch (rotate)
			{
			case 0: 
				checkMap(point, 3); // up
				checkMap(point, 0); // right
				break;
			case 1:
				checkMap(point, 0); // right
				checkMap(point, 1); // down
				break;
			case 2: 
				checkMap(point, 1); // down
				checkMap(point, 2); // left
				break;
			case 3:
				checkMap(point, 2); // left
				checkMap(point, 3); // up
				break;
			}
			break;

		case 4:
			switch (rotate)
			{
			case 0: 
				checkMap(point, 2);
				checkMap(point, 3);
				checkMap(point, 0);
				break;
			case 1: 
				checkMap(point, 3);
				checkMap(point, 0);
				checkMap(point, 1);
				break;
			case 2: 
				checkMap(point, 0);
				checkMap(point, 1);
				checkMap(point, 2);
				break;
			case 3:
				checkMap(point, 1);
				checkMap(point, 2);
				checkMap(point, 3);
				break;
			}
			break;

		case 5:
			checkMap(point, 0);
			checkMap(point, 1);
			checkMap(point, 2);
			checkMap(point, 3);
			break;
	}
}

int wallCount = 0;

void dfs(int current, int total)
{
	if (current == total)
	{
		// 여기에 cctv 체크 코드 추가

		// 방문 초기화
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				visit[i][j] = false;
			}
		}

		hideCount = r * c - wallCount; // 사각지대 카운트 초기화

		for (int i = 0; i < total; i++)
		{
			useCamera(p[i], cctvPoints[i].first, cctvPoints[i].second);
		}

		result = min(result, hideCount);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			p[current] = i;
			dfs(current + 1, total);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int item;
			cin >> item;

			map[i][j] = item;

			if (item == 6) wallCount++;

			if (item == 0 || item == 6) continue;
			cctvPoints.push_back({ item, {i, j} });
		}
	}

	result = r * c - wallCount;
	hideCount = r * c - wallCount;

	dfs(0, cctvPoints.size());

	cout << result;*/

	for (int i = 0; i < 64; i++) // 4 ^ 3
	{
		int tmp = i;
		for (int j = 0; j < 3; j++) // 3자리
		{
			cout << tmp % 4 << " ";
			tmp /= 4;
		}

		cout << '\n';
	}

	return 0;
}