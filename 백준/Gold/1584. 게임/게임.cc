#include <iostream>
#include <deque>
using namespace std;

const int maxSize = 500 + 5;
char zoneArr[maxSize][maxSize];
int lifeArr[maxSize][maxSize];

// 죽음 #, 위험 $, 일반 .

pair<int, int> offset[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool InRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first > 500 || pos.second > 500) return false;
	return true;
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
			zoneArr[i][j] = '.';
			lifeArr[i][j] = maxSize * maxSize;
		}
	}

	int n;
	cin >> n;

	for (int c = 0; c < n; c++)
	{
		pair<int, int> start, end;

		cin >> start.first >> start.second >> end.first >> end.second;

		if (start.first > end.first)
		{
			swap(start.first, end.first);
		}

		if (start.second > end.second)
		{
			swap(start.second, end.second);
		}

		for (int i = start.first; i <= end.first; i++)
		{
			for (int j = start.second; j <= end.second; j++)
			{
				zoneArr[i][j] = '$';
			}
		}
	}

	int m;
	cin >> m;

	for (int c = 0; c < m; c++)
	{
		pair<int, int> start, end;

		cin >> start.first >> start.second >> end.first >> end.second;

		if (start.first > end.first)
		{
			swap(start.first, end.first);
		}

		if (start.second > end.second)
		{
			swap(start.second, end.second);
		}

		for (int i = start.first; i <= end.first; i++)
		{
			for (int j = start.second; j <= end.second; j++)
			{
				zoneArr[i][j] = '#';
			}
		}
	}

	deque<pair<int, pair<int, int>>> dq;
	dq.push_back({ 0, {0, 0} });

	while (dq.empty() == false)
	{
		pair<int, pair<int, int>> front = dq.front(); dq.pop_front();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nearPos = { front.second.first + offset[i].first, front.second.second + offset[i].second };
			if (InRange(nearPos) == false) continue;
			if (zoneArr[nearPos.first][nearPos.second] == '#') continue;

			if (zoneArr[nearPos.first][nearPos.second] == '$')
			{
				if (lifeArr[nearPos.first][nearPos.second] > front.first + 1)
				{
					lifeArr[nearPos.first][nearPos.second] = front.first + 1;
					dq.push_back({ front.first + 1, nearPos });
				}
			}
			else
			{
				if (lifeArr[nearPos.first][nearPos.second] > front.first)
				{
					lifeArr[nearPos.first][nearPos.second] = front.first;
					dq.push_back({ front.first, nearPos });
				}
			}
		}
	}

	if (lifeArr[500][500] == maxSize * maxSize)
	{
		cout << -1;
	}
	else
	{
		cout << lifeArr[500][500];
	}

	return 0;
}