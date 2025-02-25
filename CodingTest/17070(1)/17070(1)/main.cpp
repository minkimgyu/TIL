#include <iostream>
using namespace std;

int r;
const int mapSize = 16;
int map[mapSize][mapSize];

int result = 0;

int direction = 0; // 0이 가로 1이 세로 2가 대각선

const int offsetSize = 3;
pair<int, int> offsets[offsetSize] =
{
	{0, 1},
	{1, 0},
	{1, 1},
};

void dfs(pair<int, int> pos);

void moveRight(pair<int, int> pos)
{
	int newR = pos.first + offsets[0].first;
	int newC = pos.second + offsets[0].second;
	if (newR < 0 || newC < 0 || newR >= r || newC >= r) return;
	
	pair<int, int> nextPos = { newR, newC };
	if (map[newR][newC] == 1) return;

	direction = 0;
	dfs(nextPos);
}

void moveDown(pair<int, int> pos)
{
	int newR = pos.first + offsets[1].first;
	int newC = pos.second + offsets[1].second;
	if (newR < 0 || newC < 0 || newR >= r || newC >= r) return;


	pair<int, int> nextPos = { newR, newC };
	if (map[newR][newC] == 1) return;

	direction = 1;
	dfs(nextPos);
}

void moveCross(pair<int, int> pos)
{
	for (int i = 0; i < offsetSize; i++)
	{
		int newR = pos.first + offsets[i].first;
		int newC = pos.second + offsets[i].second;

		if (newR < 0 || newC < 0 || newR >= r || newC >= r) return;
		if (map[newR][newC] == 1) return;
	}

	direction = 2;
	pair<int, int> nextPos = { pos.first + offsets[2].first, pos.second + offsets[2].second };
	dfs(nextPos);
}

void dfs(pair<int, int> pos)
{
	if (pos.first == r - 1 && pos.second == r - 1)
	{
		result += 1;
		return;
	}

	switch(direction) // 0이 가로 1이 세로 2가 대각선
	{
		case 0:
			moveRight(pos);
			moveCross(pos);
			break;
		case 1:
			moveDown(pos);
			moveCross(pos);
			break;
		case 2:
			moveRight(pos);
			moveDown(pos);
			moveCross(pos);
			break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs({ 0, 1 });
	cout << result;
	return 0;
}