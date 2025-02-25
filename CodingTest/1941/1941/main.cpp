#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int maxStudentSize = 7;
const int maxSize = 5;

char classRoom[maxSize][maxSize];

const int offsetSize = 4;
pair<int, int> offset[offsetSize] =
{
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1},
};

// vector<vector<bool>> visit;
//map<vector<vector<bool>>, bool> answerVisit; --> 이런 식으로 map에 저장할 수 있다.

bool classRoomVisit[maxSize][maxSize];
int result = 0;
map<pair<int, int>, bool> visitPoints;
pair<int, int> posArr[25];

void bfs()
{
	int maxCount = 1;
	//map<pair<int, int>, bool>::iterator begin = posArr[0]; // iterator 사용법 공부 -> iter->first, *iter
	pair<int, int> startPoint = posArr[0];

	queue<pair<int, int>> qu;
	qu.push(startPoint);
	classRoomVisit[startPoint.first][startPoint.second] = true;

	while (qu.empty() == false)
	{
		pair<int, int> front = qu.front();
		qu.pop();

		for (int i = 0; i < offsetSize; i++)
		{
			pair<int, int> point;
			point.first = front.first + offset[i].first;
			point.second = front.second + offset[i].second;

			if (point.first < 0 || point.second < 0 || point.first >= maxSize || point.second >= maxSize) continue;
			if (classRoomVisit[point.first][point.second] == true) continue; // 중복 검사
			if (visitPoints[point] == false) continue; // 앞선 조합 수에 포함되야 가능함

			qu.push(point);
			classRoomVisit[point.first][point.second] = true;
			maxCount++;
		}
	}

	if (maxCount == maxStudentSize)
	{
		result++;
	}

	// visit 초기화
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			classRoomVisit[i][j] = false;
		}
	}

	//visitPoints.clear(); // 여기서 visit 초기화 해주기
}

int visit[25];
int arr[25];

int sCount = 0;
int yCount = 0;

void dfs(int count)
{
	if (count == maxStudentSize)
	{
		bfs();
	}
	else
	{
		for (int i = 0; i < maxSize * maxSize; i++)
		{
			if (count > 0 && arr[count - 1] >= i) continue;
			if (visit[i] == true) continue;

			int add = i % maxSize;
			int multi = i / maxSize;

			char currentAlpha = classRoom[multi][add];
			if (currentAlpha == 'Y' && yCount >= 3) continue;

			switch (currentAlpha)
			{
				case 'Y':
					yCount++;
					break;
				case 'S':
					sCount++;
					break;
			}

			visit[i] = true;
			arr[count] = i;
			posArr[count] = { multi, add };
			visitPoints[{ multi, add }] = true;

			dfs(count + 1);

			switch (currentAlpha)
			{
			case 'Y':
				yCount--;
				break;
			case 'S':
				sCount--;
				break;
			}

			visit[i] = false;
			visitPoints[{ multi, add }] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < maxSize; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < maxSize; j++)
		{
			char item = line[j];
			classRoom[i][j] = item;
		}
	}

	dfs(0);
	cout << result;
	return 0;
}