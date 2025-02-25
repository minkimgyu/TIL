#include <iostream>
#include <queue>
#include <map>
using namespace std;

int r, c;

const int maxSize = 300;
pair<int, bool> arr[maxSize][maxSize];

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iceCount = 0;

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int item;
			cin >> item;

			bool isIce = item > 0;

			if (isIce) iceCount++;
			arr[i][j] = { item, isIce };
		}
	}

	// 반례
	// 
	// 얼음이 원래 하나인 경우
	// 얼음이 한번에 다 녹는 경우
	if (iceCount == 1)
	{
		cout << 0;
		return 0;
	}


	int loopTime = 0;

	while (1)
	{
		loopTime++;
		// 얼음을 부수고
		// 얼음을 false로 만들어주는 코드가 필요함

		bool nowHaveDFSPoint = false;
		pair<int, int> bfsPoint;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j].second == false) continue;

				for (int k = 0; k < offsetSize; k++)
				{
					pair<int, int> newPos = { i + offsets[k].first, j + offsets[k].second };
					if (newPos.first < 0 || newPos.second < 0 || newPos.first >= r || newPos.second >= c) continue;
					if (arr[newPos.first][newPos.second].second == true) continue; // 아직 얼음인 경우 continue;

					arr[i][j].first -= 1;
					if (arr[i][j].first == 0)
					{
						iceCount--;
						break;
					}
				}

				if (nowHaveDFSPoint == false && arr[i][j].first > 0)
				{
					nowHaveDFSPoint = true;
					bfsPoint = { i, j };
				}
			}
		}

		if (iceCount == 0) // 얼음이 한번에 다 녹는 경우
		{
			cout << 0;
			return 0;
		}

		// 얼음을 부순다.
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j].first == 0)
				{
					arr[i][j].second = false;
				}
			}
		}

		map<pair<int, int>, bool> visit; // 위치, 방문 순서
		queue<pair<int, int>> q;
		int visitCount = 0;

		bool isOnePiece = false;

		q.push(bfsPoint);
		visit[bfsPoint] = true;
		visitCount++;

		while (q.empty() == false)
		{
			pair<int, int> front = q.front();
			q.pop();

			for (int k = 0; k < offsetSize; k++)
			{
				pair<int, int> newPos = { front.first + offsets[k].first, front.second + offsets[k].second };
				if (newPos.first < 0 || newPos.second < 0 || newPos.first >= r || newPos.second >= c) continue;
				if (visit[newPos] == true) continue; // 방문했다면 continue;
				if (arr[newPos.first][newPos.second].second == false) continue; // 얼음이 아니면 continue;

				q.push(newPos);
				visit[newPos] = true;
				visitCount++;

				if (visitCount == iceCount) // 방문한 얼음의 개수가 전체 얼음의 개수와 같다면 아직 하나임
				{
					isOnePiece = true;
					break;
				}
			}

			if (isOnePiece == true) break;
		}

		if (isOnePiece == false)
		{
			cout << loopTime;
			break;
		}
	}

	return 0;
}