#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c;
char map[20][20];
bool visit[26];

int result = 0;
int moveCount = 0;

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
};

void dfs(pair<int, int> pos) // r, c
{
	char alpha = map[pos.first][pos.second];
	if (visit[alpha - 'A'] == true) return;

	visit[alpha - 'A'] = true;
	moveCount++;
	result = max(result, moveCount);

	for (int i = 0; i < offsetSize; i++)
	{
		int tmpR = pos.first + offsets[i].first;
		int tmpC = pos.second + offsets[i].second;

		if (tmpR < 0 || tmpR >= r || tmpC < 0 || tmpC >= c) continue;
		dfs({ tmpR, tmpC });
	}

	visit[alpha - 'A'] = false;
	moveCount--;
}

int main()
{
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

	dfs({ 0, 0 });

	cout << result;
	return 0;
}