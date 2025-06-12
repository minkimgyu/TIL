#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int h, w;

const int maxSize = 100 + 5;
char mapArr[maxSize][maxSize];
int valueArr[maxSize][maxSize];
int totalValueArr[maxSize][maxSize];

pair<int, int> offset[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool InRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first > h + 1 || pos.second > w + 1) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int y = 0; y < t; y++)
	{
		cin >> h >> w;

		vector<pair<int, int>> entryPoints;

		for (int i = 1; i <= h; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= w; j++)
			{
				mapArr[i][j] = s[j - 1];
				if (mapArr[i][j] == '$')
				{
					entryPoints.push_back({ i, j });
				}
			}
		}

		entryPoints.push_back({ 0, 0 }); // 상근이 시작 지점

		for (int z = 0; z < 3; z++)
		{
			for (int i = 0; i <= h + 1; i++)
			{
				for (int j = 0; j <= w + 1; j++)
				{
					valueArr[i][j] = maxSize * maxSize;
				}
			}

			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pQ;
			pQ.push({ 0, entryPoints[z] });
			valueArr[entryPoints[z].first][entryPoints[z].second] = 0;

			while (pQ.empty() == false)
			{
				pair<int, pair<int, int>> front = pQ.top(); pQ.pop();

				for (int i = 0; i < 4; i++)
				{
					pair<int, int> pos = { front.second.first + offset[i].first, front.second.second + offset[i].second };
					if (InRange(pos) == false) continue;

					if (mapArr[pos.first][pos.second] == '*') continue;
					if (mapArr[pos.first][pos.second] == '#' && valueArr[pos.first][pos.second] > front.first + 1)
					{
						valueArr[pos.first][pos.second] = front.first + 1;
						pQ.push({ front.first + 1, pos });
					}
					else if (mapArr[pos.first][pos.second] != '#' && valueArr[pos.first][pos.second] > front.first)
					{
						valueArr[pos.first][pos.second] = front.first;
						pQ.push({ front.first, pos });
					}
				}
			}

			for (int i = 0; i <= h + 1; i++)
			{
				for (int j = 0; j <= w + 1; j++)
				{
					totalValueArr[i][j] += valueArr[i][j];
				}
			}

		}

		int result = maxSize * maxSize;

		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (mapArr[i][j] == '#')
				{
					totalValueArr[i][j] -= 2;
				}
				// 만약 탈출을 위해 방문해야 하는 문이면 강제로 3이상 나옴
				// 따라서 0이면 방문하지 않아도 탈출 가능하다는 거임
				result = min(result, totalValueArr[i][j]);
				totalValueArr[i][j] = 0;
				mapArr[i][j] = ' ';
			}
		}

		cout << result;
		if (y != t - 1) cout << '\n';
	}

	return 0;
}