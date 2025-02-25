#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

const int offset = 5;

// r, c
int map[40 + offset][40 + offset];

// r, c
const int shapeCount = 4;
vector<vector<int>> shape[100 + offset][shapeCount]; // 모양이 4개임

bool OutOfRange(pair<int, int> worldPoint)
{
	return worldPoint.first < 0 || worldPoint.first >= n || worldPoint.second < 0 || worldPoint.second >= m;
}

pair<int, pair<int, int>> NowFitPosition(int shapeIndex)
{
	// 모양 인덱스, { r, c } 좌표
	pair<int, pair<int, int>> data;

	for (int t = 0; t < shapeCount; t++)
	{
		vector<vector<int>> pickShape = shape[shapeIndex][t];

		int row = pickShape.size();
		int col = pickShape[0].size();

		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				pair<int, int> startPoint = { r, c };

				bool outOfRange = false;
				bool nowOverlap = false;

				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < col; j++)
					{
						pair<int, int> localPoint = { i, j }; // 스티커 좌표
						pair<int, int> worldPoint = { r + i, c + j }; // 맵 좌표

						outOfRange = OutOfRange(worldPoint);
						if (outOfRange == true) break;

						int mapFill = map[worldPoint.first][worldPoint.second];
						int shapeFill = pickShape[localPoint.first][localPoint.second];

						// 둘 다 1인 경우 -> 이미 블록이 있는 경우
						if (mapFill == 1 && shapeFill == 1)
						{
							nowOverlap = true;
							break;
						}
					}
					if (outOfRange == true || nowOverlap == true) break;
				}

				// 겹치지 않는 경우임
				if (outOfRange == false && nowOverlap == false)
				{
					data = { t, {r, c} };
					return data;
				}
			}
		}
	}

	data = { -1, {0, 0} };
	return data;
}

void FillShape(int shapeIndex)
{
	for (int t = 1; t < shapeCount; t++)
	{
		vector<vector<int>> defaultShape = shape[shapeIndex][0];

		int row = defaultShape.size();
		int col = defaultShape[0].size();

		vector<vector<int>> newShape;

		switch (t)
		{
			case 0:
				for (int i = 0; i < row; i++)
				{
					vector<int> colVec;
					for (int j = 0; j < col; j++)
					{
						colVec.push_back(defaultShape[i][j]);
					}
					newShape.push_back(colVec);
				}
				break;
			case 1:
				for (int i = 0; i < col; i++)
				{
					vector<int> colVec;
					for (int j = row - 1; j > -1; j--)
					{
						colVec.push_back(defaultShape[j][i]);
					}
					newShape.push_back(colVec);
				}
				break;
			case 2:
				for (int i = row - 1; i > -1; i--)
				{
					vector<int> colVec;
					for (int j = col - 1; j > -1; j--)
					{
						colVec.push_back(defaultShape[i][j]);
					}
					newShape.push_back(colVec);
				}
				break;
			case 3:
				for (int i = col - 1; i > -1; i--)
				{
					vector<int> colVec;
					for (int j = 0; j < row; j++)
					{
						colVec.push_back(defaultShape[j][i]);
					}
					newShape.push_back(colVec);
				}
				break;
			default:
				break;
		}

		shape[shapeIndex][t] = newShape;
	}
}

int maxFillCount = 0;

void dfs(int attachCount, int fillCount)
{
	if (attachCount == k) return; // 더 이상 붙일 스티커가 없다면 return;

	pair<int, pair<int, int>> data = NowFitPosition(attachCount);

	// 붙이는 코드
	int shapeIndex = data.first;
	if (shapeIndex == -1)
	{
		dfs(attachCount + 1, fillCount); // 맞는 위치가 없다면 버리고 다음 스티커를 붙인다.
		return; 
	}

	pair<int, int> point = data.second;

	int row = shape[attachCount][shapeIndex].size();
	int col = shape[attachCount][shapeIndex][0].size();

	int currentFillCount = 0;

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			pair<int, int> localPoint = { r, c }; // 스티커 좌표
			pair<int, int> worldPoint = { r + point.first, c + point.second }; // 맵 좌표

			if (shape[attachCount][shapeIndex][r][c] == 1)
			{
				currentFillCount++;
				map[worldPoint.first][worldPoint.second] = shape[attachCount][shapeIndex][r][c]; // 넣기
			}
		}
	}

	// 채운 칸 구하기
	maxFillCount = max(maxFillCount, fillCount + currentFillCount);
	dfs(attachCount + 1, fillCount + currentFillCount);

	// 스티커를 제거하는 코드
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			pair<int, int> localPoint = { r, c }; // 스티커 좌표
			pair<int, int> worldPoint = { r + point.first, c + point.second }; // 맵 좌표

			if (shape[attachCount][shapeIndex][r][c] == 1)
			{
				map[worldPoint.first][worldPoint.second] = 0; // 0 넣어서 스티커 제거하기
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;

		vector<vector<int>> row;

		for (int j = 0; j < r; j++)
		{
			vector<int> col;
			for (int k = 0; k < c; k++)
			{
				int tmp;
				cin >> tmp;
				col.push_back(tmp);
			}
			row.push_back(col);
		}

		shape[i][0] = row;
	}

	for (int i = 0; i < k; i++) FillShape(i); // 모든 블록의 상태 모양을 채워준다.
	
	dfs(0, 0);
	cout << maxFillCount;
	return 0;
}