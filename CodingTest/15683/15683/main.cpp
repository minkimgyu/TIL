#include <iostream>
#include <vector>
using namespace std;

const int mapSize = 8;
const int directionCount = 4;

vector<pair<int, pair<int, int>>> cctvs;
int cctvCount;

int n, m;

int copyMapArr[mapSize][mapSize];

int mapArr[mapSize][mapSize];
int directionArr[mapSize];

int totalCount;
int copyTotalCount;

int result;

pair<int, int> directionPos[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

// n과 m을 이용해서 방향 계산을 해볼 수 있을 듯함

void dfs(int r, int c, int direction)
{
	r += directionPos[direction].first;
	c += directionPos[direction].second;

	if (r < 0 || c < 0 || r >= n || c >= m) return;
	if(copyMapArr[r][c] == 6) return; // 벽인 경우

	// cctv 위치가 아닌 경우 방문 표시
	if (0 >= copyMapArr[r][c] || copyMapArr[r][c] >= 6 && copyMapArr[r][c] != 9)
	{
		copyMapArr[r][c] = 9;
		copyTotalCount -= 1;
	}

	result = min(result, copyTotalCount);
	dfs(r, c, direction);
}

void loop(int count)
{
	if (count == cctvCount)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				copyMapArr[i][j] = mapArr[i][j]; // arr 복사해주기
			}
		}

		copyTotalCount = totalCount;

		// 여기에서 direction 채크
		for (int i = 0; i < cctvCount; i++)
		{
			int direction = directionArr[i];

			int cctvName = cctvs[i].first;
			pair<int, int> cctvPos = cctvs[i].second;

			switch (cctvName)
			{
				case 1:
					dfs(cctvPos.first, cctvPos.second, direction);
					break;

				case 2:
					dfs(cctvPos.first, cctvPos.second, (0 + direction) % directionCount);
					dfs(cctvPos.first, cctvPos.second, (2 + direction) % directionCount);
					break;

				case 3:
					dfs(cctvPos.first, cctvPos.second, (0 + direction) % directionCount);
					dfs(cctvPos.first, cctvPos.second, (1 + direction) % directionCount);
					break;

				case 4:
					dfs(cctvPos.first, cctvPos.second, (0 + direction) % directionCount);
					dfs(cctvPos.first, cctvPos.second, (1 + direction) % directionCount);
					dfs(cctvPos.first, cctvPos.second, (2 + direction) % directionCount);
					break;

				case 5:
					dfs(cctvPos.first, cctvPos.second, 0);
					dfs(cctvPos.first, cctvPos.second, 1);
					dfs(cctvPos.first, cctvPos.second, 2);
					dfs(cctvPos.first, cctvPos.second, 3);
					break;

				default:
					break;
			}
		}
	}
	else
	{
		for (int i = 0; i < directionCount; i++)
		{
			directionArr[count] = i;
			loop(count + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	totalCount = n * m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int item;
			cin >> item;
			
			if (0 < item && item < 6)
			{
				cctvs.push_back({ item, { i, j } });
			}

			mapArr[i][j] = item;
			if (item != 0)
			{
				totalCount -= 1;
			}
		}
	}
	cctvCount = cctvs.size();

	if (n == 1 && m == 1)
	{
		if (mapArr[0][0] == 0) cout << 1;
		else cout << 0;
		return 0;
	}

	if (cctvCount == 0)
	{
		cout << totalCount;
		return 0;
	}

	result = totalCount;
	loop(0);
	cout << result;

	return 0;
}