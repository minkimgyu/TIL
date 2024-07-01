#include <iostream>
#include <vector>
using namespace std;

int map[50][50]{0, };

vector<pair<int, int>> offsets = { {0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	pair<int, int> startPos;
	int d;
	cin >> startPos.second >> startPos.first >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int result = 0;

	while (1)
	{
		if (map[startPos.second][startPos.first] == 0)
		{
			map[startPos.second][startPos.first] = 2;
			result++;
		}

		bool canClean = false;
		
		for (int i = 0; i < offsets.size(); i++)
		{
			int x = startPos.first + offsets[i].first;
			int y = startPos.second + offsets[i].second;

			if (map[y][x] == 0)
			{
				canClean = true;
				break;
			}
		}

		// 0 1 2 3 

		if (canClean)
		{
			d -= 1;
			if (d == -1) d = 3;

			pair<int, int> frontPos = startPos;

			frontPos.first += offsets[d].first;
			frontPos.second += offsets[d].second;

			if (map[frontPos.second][frontPos.first] == 0)
			{
				startPos = frontPos;
			}
		}
		else
		{
			pair<int, int> backPos = startPos;

			backPos.first -= offsets[d].first;
			backPos.second -= offsets[d].second;

			if (map[backPos.second][backPos.first] == 1) break;
			else startPos = backPos;
		}
	}

	cout << result;

	return 0;
}