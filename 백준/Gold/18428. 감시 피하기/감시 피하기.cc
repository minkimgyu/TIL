#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 6 + 1;
int arr[maxSize][maxSize];

int caseArr[maxSize][maxSize];

const int blockPointSize = 3;

vector<pair<int, int>> tPoints;
vector<pair<int, int>> blockPoints;

int blockPointArr[blockPointSize + 1];

// 1. 조합 구하기
// 2. 조합에 따라 장애물 배치
// 3. left, right, up, down 확인하기

int n;
bool canFindStudent = false;
bool result = false;

bool isOutOfRange(pair<int, int> currentPoint)
{
	return currentPoint.first < 0 || currentPoint.second < 0 || currentPoint.first >= n || currentPoint.second >= n;
}

void moveLeft(pair<int, int> currentPoint)
{
	bool outOfRange = isOutOfRange(currentPoint); // 범위 나간 경우
	if (outOfRange == true) return;

	bool isBlock = caseArr[currentPoint.first][currentPoint.second] == -1; // 장애물의 경우
	if (isBlock == true) return;

	bool findStudent = caseArr[currentPoint.first][currentPoint.second] == 1; // 학생의 경우
	if (findStudent == true)
	{
		canFindStudent = true;
		return;
	}

	moveLeft({ currentPoint.first, currentPoint.second - 1 });
}

void moveRight(pair<int, int> currentPoint)
{
	bool outOfRange = isOutOfRange(currentPoint); // 범위 나간 경우
	if (outOfRange == true) return;

	bool isBlock = caseArr[currentPoint.first][currentPoint.second] == -1; // 장애물의 경우
	if (isBlock == true) return;

	bool findStudent = caseArr[currentPoint.first][currentPoint.second] == 1; // 학생의 경우
	if (findStudent == true)
	{
		canFindStudent = true;
		return;
	}

	moveRight({ currentPoint.first, currentPoint.second + 1 });
}


void moveUp(pair<int, int> currentPoint)
{
	bool outOfRange = isOutOfRange(currentPoint); // 범위 나간 경우
	if (outOfRange == true) return;

	bool isBlock = caseArr[currentPoint.first][currentPoint.second] == -1; // 장애물의 경우
	if (isBlock == true) return;

	bool findStudent = caseArr[currentPoint.first][currentPoint.second] == 1; // 학생의 경우
	if (findStudent == true)
	{
		canFindStudent = true;
		return;
	}

	moveUp({ currentPoint.first - 1, currentPoint.second });
}


void moveDown(pair<int, int> currentPoint)
{
	bool outOfRange = isOutOfRange(currentPoint); // 범위 나간 경우
	if (outOfRange == true) return;

	bool isBlock = caseArr[currentPoint.first][currentPoint.second] == -1; // 장애물의 경우
	if (isBlock == true) return;

	bool findStudent = caseArr[currentPoint.first][currentPoint.second] == 1; // 학생의 경우
	if (findStudent == true)
	{
		canFindStudent = true;
		return;
	}

	moveDown({ currentPoint.first + 1, currentPoint.second });
}

void seeAllCase()
{
	int tSize = tPoints.size();
	for (int i = 0; i < tSize; i++)
	{
		moveUp(tPoints[i]); if (canFindStudent == true) break;
		moveDown(tPoints[i]); if (canFindStudent == true) break;
		moveLeft(tPoints[i]); if (canFindStudent == true) break;
		moveRight(tPoints[i]); if (canFindStudent == true) break;
	}
}

void findCase(int m)
{
	if (m == blockPointSize)
	{
		// 장애물 배치
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				caseArr[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < blockPointSize; i++)
		{
			caseArr[blockPoints[blockPointArr[i]].first][blockPoints[blockPointArr[i]].second] = -1; // 장애물은 -1로 등록
		}

		canFindStudent = false; // 초기화
		seeAllCase();

		if (canFindStudent == false)
		{
			result = true; // 못 찾은 경우 true로 맞춰주기
		}
	}
	else
	{
		int pointSize = blockPoints.size();
		for (int i = 0; i < pointSize; i++)
		{
			if (m > 0 && blockPointArr[m - 1] >= i) continue;
			blockPointArr[m] = i;
			findCase(m + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char item;
			cin >> item;

			switch (item)
			{
			case 'X':
				arr[i][j] = 0;
				blockPoints.push_back({ i, j });
				break;
			case 'S':
				arr[i][j] = 1;
				break;
			case 'T':
				arr[i][j] = 2;
				tPoints.push_back({ i, j });
				break;
			default:
				break;
			}
		}
	}

	findCase(0);

	if (result == true) cout << "YES"; // 찾은 경우
	else cout << "NO";

	return 0;
}