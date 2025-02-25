#include <iostream>
#include <string>
using namespace std;

int r, c;

const int mapSize = 20;
char map[mapSize][mapSize];

const int alphaSize = 26;
bool visit[alphaSize];

const int offsetSize = 4;
pair<int, int> offset[offsetSize] =
{
	{-1, 0},
	{0, -1},
	{1, 0},
	{0, 1},
};

int maxVisitCount = -1;

void dfs(pair<int, int> pos, int visitCount)
{
	char item = map[pos.second][pos.first];

	int alphaIndex = (int)item - (int)'A';
	visit[alphaIndex] = true;
	visitCount++;

	if (visitCount > maxVisitCount) maxVisitCount = visitCount;

	for (int i = 0; i < offsetSize; i++)
	{
		int x = pos.first + offset[i].first;
		int y = pos.second + offset[i].second;

		if (x < 0 || y < 0 || x >= c || y >= r) continue;

		char item = map[y][x];
		int alphaIndex = (int)item - (int)'A';
		if (visit[alphaIndex] == true) continue;

		dfs({ x, y }, visitCount);
	}

	visit[alphaIndex] = false;
	visitCount--;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		string line;
		getline(cin, line);
		for (int j = 0; j < c; j++)
		{
			map[i][j] = line[j];
		}
	}

	dfs({ 0, 0 }, 0);

	cout << maxVisitCount;
	return 0;
}