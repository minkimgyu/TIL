#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 9;
int arr[maxSize][maxSize];

vector<int> checkVec;
vector<pair<int, int>> emptyPoints;

void checkCol(pair<int, int> point)
{
	bool containNum[maxSize + 1];
	for (int i = 0; i < maxSize + 1; i++) containNum[i] = false; // 초기화

	for (int i = 0; i < maxSize; i++)
	{
		if (arr[point.first][i] != 0) containNum[arr[point.first][i]] = true;
	}

	for (int i = 1; i < maxSize + 1; i++)
	{
		if (containNum[i] == false) checkVec.push_back(i);
	}
}

void checkRow(pair<int, int> point)
{
	bool containNum[maxSize + 1];
	for (int i = 0; i < maxSize + 1; i++) containNum[i] = false; // 초기화

	for (int i = 0; i < maxSize; i++)
	{
		if (arr[i][point.second] != 0) containNum[arr[i][point.second]] = true;
	}

	for (int i = 1; i < maxSize + 1; i++)
	{
		if (containNum[i] == false) checkVec.push_back(i);
	}
}

pair<pair<int, int>, pair<int, int>> rectRanges[9] =
{
	{{0, 0}, {2, 2}}, {{0, 3}, {2, 5}}, {{0, 6}, {2, 8}},
	{{3, 0}, {5, 2}}, {{3, 3}, {5, 5}}, {{3, 6}, {5, 8}},
	{{6, 0}, {8, 2}}, {{6, 3}, {8, 5}}, {{6, 6}, {8, 8}},
};

void checkRect(pair<int, int> point)
{
	int rangeIndex = 0;
	for (int i = 0; i < maxSize; i++)
	{
		if (rectRanges[i].first.first <= point.first && point.first <= rectRanges[i].second.first
			&& rectRanges[i].first.second <= point.second && point.second <= rectRanges[i].second.second)
		{
			rangeIndex = i;
			break;
		}
	}

	bool containNum[maxSize + 1];
	for (int i = 0; i < maxSize + 1; i++) containNum[i] = false; // 초기화

	for (int i = rectRanges[rangeIndex].first.first; i <= rectRanges[rangeIndex].second.first; i++)
	{
		for (int j = rectRanges[rangeIndex].first.second; j <= rectRanges[rangeIndex].second.second; j++)
		{
			if (arr[i][j] != 0) containNum[arr[i][j]] = true;
		}
	}

	for (int i = 1; i < maxSize + 1; i++)
	{
		if (containNum[i] == false) checkVec.push_back(i);
	}
}

bool alreadyClear = false;

void dfs(int loopCount)
{
	if (alreadyClear == true)
	{
		return;
	}

	if (loopCount == emptyPoints.size()) // 다 찾은 경우
	{
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				cout << arr[i][j];
				if(j != maxSize - 1) cout << " ";
			}

			if(i != maxSize - 1) cout << '\n';
		}

		alreadyClear = true;
		return;
	}

	pair<int, int> point = emptyPoints[loopCount];

	int numCount[maxSize + 1];
	for (int i = 0; i < maxSize + 1; i++) numCount[i] = 0; // 초기화

	checkVec.clear();

	checkRow(point);
	checkCol(point);
	checkRect(point);

	int checkVecSize = checkVec.size();
	for (int i = 0; i < checkVecSize; i++)
	{
		numCount[checkVec[i]] += 1;
	}

	for (int i = 1; i < maxSize + 1; i++)
	{
		if (numCount[i] == 3)
		{
			arr[point.first][point.second] = i;
			dfs(loopCount + 1);
			arr[point.first][point.second] = 0;
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
		for (int j = 0; j < maxSize; j++)
		{
			int item;
			cin >> item;
			arr[i][j] = item;

			if(item == 0) emptyPoints.push_back({ i , j });
		}
	}

	dfs(0);
	return 0;
}