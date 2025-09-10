#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int maxSize = 50 + 5;
char map[maxSize][maxSize];

const int Inf = maxSize * maxSize;

const int dirSize = 4;
// r, c, dir
// ↑ → ↓ ←
int visit[maxSize][maxSize][dirSize];
int n;

pair<int, int> dirs[dirSize] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

pair<int, int> changeDir(int dir)
{
	pair<int, int> newDir;
	if (dir == 0 || dir == 2)
	{
		newDir.first = 1;
		newDir.second = 3;
	}
	else if(dir == 1 || dir == 3)
	{
		newDir.first = 0;
		newDir.second = 2;
	}

	return newDir;
}

bool outOfRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	pair<int, int> startPos;

	int result = Inf;
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			visit[i][j][0] = Inf;
			visit[i][j][1] = Inf;
			visit[i][j][2] = Inf;
			visit[i][j][3] = Inf;
		}
	}

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j];
			if (map[i][j] == '#') startPos = { i, j };
		}
	}

	map[startPos.first][startPos.second] = '*';

	queue<pair<pair<int, int>, int>> q; // pos, dir

	for (int i = 0; i < dirSize; i++)
	{
		visit[startPos.first][startPos.second][i] = 0;
		q.push({ { startPos.first, startPos.second }, i });
	}

	while (q.empty() == false)
	{
		pair<pair<int, int>, int> front = q.front(); q.pop();

		pair<int, int> curPos = front.first;
		int curDir = front.second;

		pair<int, int> nxtPos = { curPos.first + dirs[curDir].first, curPos.second + dirs[curDir].second };
		if (outOfRange(nxtPos) == true) continue;

		// 거울 위치에 도달한 경우
		if (map[nxtPos.first][nxtPos.second] == '!')
		{
			// 거울 설치 안 하는 경우
			if (visit[nxtPos.first][nxtPos.second][curDir] > visit[curPos.first][curPos.second][curDir])
			{
				visit[nxtPos.first][nxtPos.second][curDir] = visit[curPos.first][curPos.second][curDir];
				q.push({ nxtPos, curDir });
			}

			pair<int, int> changedDir = changeDir(curDir);
			if (visit[nxtPos.first][nxtPos.second][changedDir.first] > visit[curPos.first][curPos.second][curDir] + 1)
			{
				visit[nxtPos.first][nxtPos.second][changedDir.first] = visit[curPos.first][curPos.second][curDir] + 1;
				q.push({ nxtPos, changedDir.first });
			}

			if (visit[nxtPos.first][nxtPos.second][changedDir.second] > visit[curPos.first][curPos.second][curDir] + 1)
			{
				visit[nxtPos.first][nxtPos.second][changedDir.second] = visit[curPos.first][curPos.second][curDir] + 1;
				q.push({ nxtPos, changedDir.second });
			}
		}
		// 못 지나가는 위치에 도달한 경우
		else if (map[nxtPos.first][nxtPos.second] == '*')
		{
			continue;
		}
		// 일반 위치에 도달한 경우
		else if (map[nxtPos.first][nxtPos.second] == '.')
		{
			// 현재 거울이 더 작은 경우만 진행
			if (visit[nxtPos.first][nxtPos.second][curDir] > visit[curPos.first][curPos.second][curDir])
			{
				visit[nxtPos.first][nxtPos.second][curDir] = visit[curPos.first][curPos.second][curDir];
				q.push({ nxtPos, curDir });
			}
		}
		// 목적지에 도달한 경우
		else if (map[nxtPos.first][nxtPos.second] == '#')
		{
			// 현재 거울이 더 작은 경우 결과 업데이트
			if (visit[nxtPos.first][nxtPos.second][curDir] > visit[curPos.first][curPos.second][curDir])
			{
				visit[nxtPos.first][nxtPos.second][curDir] = visit[curPos.first][curPos.second][curDir];
				result = min(result, visit[nxtPos.first][nxtPos.second][curDir]);
			}
		}
	}

	cout << result;
	return 0;
}