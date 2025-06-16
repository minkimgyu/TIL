#include <iostream>
#include <queue>
using namespace std;

const int maxSize = 100 + 5;
int arrMap[maxSize][maxSize];
bool visit[maxSize][maxSize];

pair<int, int> offset[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
pair<int, int> startPos[maxSize * maxSize];

int n, m;

bool InRange(pair<int, int> pos)
{
	if (pos.first < 1 || pos.second < 1 || pos.first > n || pos.second > m) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		pair<int, int> pos;
		cin >> pos.first >> pos.second;

		startPos[i] = pos;
		arrMap[pos.first][pos.second] = 1;
	}

	int result = 0;

	for (int i = 0; i < k; i++)
	{
		pair<int, int> pos = startPos[i];
		queue<pair<int, int>> q;

		if (visit[pos.first][pos.second] == true) continue;

		visit[pos.first][pos.second] = true;
		q.push(pos);
		int currentResult = 1;

		while (q.empty() == false)
		{
			pair<int, int> front = q.front(); q.pop();

			for (int j = 0; j < 4; j++)
			{
				pair<int, int> nearPos = { front.first + offset[j].first, front.second + offset[j].second };
				if (InRange(nearPos) == false) continue;
				if (arrMap[nearPos.first][nearPos.second] == 0) continue;
				if (visit[nearPos.first][nearPos.second] == true) continue;

				visit[nearPos.first][nearPos.second] = true;
				q.push(nearPos);
				currentResult++;
				result = max(result, currentResult);
			}
		}
	}

	cout << result;
	return 0;
}