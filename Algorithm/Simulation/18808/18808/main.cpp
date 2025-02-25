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
vector<vector<int>> shape[100 + offset][shapeCount]; // ����� 4����

bool OutOfRange(pair<int, int> worldPoint)
{
	return worldPoint.first < 0 || worldPoint.first >= n || worldPoint.second < 0 || worldPoint.second >= m;
}

pair<int, pair<int, int>> NowFitPosition(int shapeIndex)
{
	// ��� �ε���, { r, c } ��ǥ
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
						pair<int, int> localPoint = { i, j }; // ��ƼĿ ��ǥ
						pair<int, int> worldPoint = { r + i, c + j }; // �� ��ǥ

						outOfRange = OutOfRange(worldPoint);
						if (outOfRange == true) break;

						int mapFill = map[worldPoint.first][worldPoint.second];
						int shapeFill = pickShape[localPoint.first][localPoint.second];

						// �� �� 1�� ��� -> �̹� ����� �ִ� ���
						if (mapFill == 1 && shapeFill == 1)
						{
							nowOverlap = true;
							break;
						}
					}
					if (outOfRange == true || nowOverlap == true) break;
				}

				// ��ġ�� �ʴ� �����
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
	if (attachCount == k) return; // �� �̻� ���� ��ƼĿ�� ���ٸ� return;

	pair<int, pair<int, int>> data = NowFitPosition(attachCount);

	// ���̴� �ڵ�
	int shapeIndex = data.first;
	if (shapeIndex == -1)
	{
		dfs(attachCount + 1, fillCount); // �´� ��ġ�� ���ٸ� ������ ���� ��ƼĿ�� ���δ�.
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
			pair<int, int> localPoint = { r, c }; // ��ƼĿ ��ǥ
			pair<int, int> worldPoint = { r + point.first, c + point.second }; // �� ��ǥ

			if (shape[attachCount][shapeIndex][r][c] == 1)
			{
				currentFillCount++;
				map[worldPoint.first][worldPoint.second] = shape[attachCount][shapeIndex][r][c]; // �ֱ�
			}
		}
	}

	// ä�� ĭ ���ϱ�
	maxFillCount = max(maxFillCount, fillCount + currentFillCount);
	dfs(attachCount + 1, fillCount + currentFillCount);

	// ��ƼĿ�� �����ϴ� �ڵ�
	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			pair<int, int> localPoint = { r, c }; // ��ƼĿ ��ǥ
			pair<int, int> worldPoint = { r + point.first, c + point.second }; // �� ��ǥ

			if (shape[attachCount][shapeIndex][r][c] == 1)
			{
				map[worldPoint.first][worldPoint.second] = 0; // 0 �־ ��ƼĿ �����ϱ�
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

	for (int i = 0; i < k; i++) FillShape(i); // ��� ����� ���� ����� ä���ش�.
	
	dfs(0, 0);
	cout << maxFillCount;
	return 0;
}