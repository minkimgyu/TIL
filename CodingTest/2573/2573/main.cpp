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

	// �ݷ�
	// 
	// ������ ���� �ϳ��� ���
	// ������ �ѹ��� �� ��� ���
	if (iceCount == 1)
	{
		cout << 0;
		return 0;
	}


	int loopTime = 0;

	while (1)
	{
		loopTime++;
		// ������ �μ���
		// ������ false�� ������ִ� �ڵ尡 �ʿ���

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
					if (arr[newPos.first][newPos.second].second == true) continue; // ���� ������ ��� continue;

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

		if (iceCount == 0) // ������ �ѹ��� �� ��� ���
		{
			cout << 0;
			return 0;
		}

		// ������ �μ���.
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

		map<pair<int, int>, bool> visit; // ��ġ, �湮 ����
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
				if (visit[newPos] == true) continue; // �湮�ߴٸ� continue;
				if (arr[newPos.first][newPos.second].second == false) continue; // ������ �ƴϸ� continue;

				q.push(newPos);
				visit[newPos] = true;
				visitCount++;

				if (visitCount == iceCount) // �湮�� ������ ������ ��ü ������ ������ ���ٸ� ���� �ϳ���
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