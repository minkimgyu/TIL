#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int maxSize = 300 + 5;
char mapArr[maxSize][maxSize];
bool visit[maxSize][maxSize];

pair<int, int> offset[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int n, m;

bool InRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	pair<int, int> start, end;
	cin >> start.first >> start.second >> end.first >> end.second;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			mapArr[i][j] = s[j];
			if (s[j] == '*')
			{
				start = { i, j };
			}

			if (s[j] == '#')
			{
				end = { i, j };
			}
		}
	}

	queue<pair<int, int>> q;
	int result = 0;
	bool canFind = false;

	while (1)
	{
		q.push(start);
		result++;
		while (q.empty() == false)
		{
			pair<int, int> front = q.front(); q.pop();

			for (int i = 0; i < 4; i++)
			{
				pair<int, int> nearPos = { front.first + offset[i].first, front.second + offset[i].second };
				if (InRange(nearPos) == false) continue;
				if (visit[nearPos.first][nearPos.second] == true) continue;

				if (mapArr[nearPos.first][nearPos.second] == '#')
				{
					canFind = true;
					break;
				}

				if (mapArr[nearPos.first][nearPos.second] == '1')
				{
					mapArr[nearPos.first][nearPos.second] = '0';
					visit[nearPos.first][nearPos.second] = true;
				}
				else if (mapArr[nearPos.first][nearPos.second] == '0')
				{
					visit[nearPos.first][nearPos.second] = true;
					q.push(nearPos);
				}
			}

			if (canFind) break;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visit[i][j] = false;
			}
		}

		if (canFind) break;
	}

	cout << result;
	return 0;
}