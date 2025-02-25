#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 17;
int map[maxSize][maxSize];

int n;
int direction = 0; // --> 0이 가로, 1이 세로, 2가 대각선
int result = 0;

const int offsetSize = 3;
pair<int, int> offsets[offsetSize] =
{
	{0, 1},
	{1, 0},
	{1, 1},
};

void dfs(pair<int, int> startPos);

void MoveLeft(pair<int, int> pos)
{
	int r = pos.first + offsets[0].first;
	int c = pos.second + offsets[0].second;

	if (r < 1 || c < 1 || r > n || c > n) return;
	if (map[r][c] == 1) return;

	direction = 0;
	dfs({r, c});
}

void MoveDown(pair<int, int> pos)
{
	int r = pos.first + offsets[1].first;
	int c = pos.second + offsets[1].second;

	if (r < 1 || c < 1 || r > n || c > n) return;
	if (map[r][c] == 1) return;

	direction = 1;
	dfs({ r, c });
}

void MoveCross(pair<int, int> pos)
{
	for (int i = 0; i < offsetSize; i++)
	{
		int r = pos.first + offsets[i].first;
		int c = pos.second + offsets[i].second;

		if (r < 1 || c < 1 || r > n || c > n) return;
		if (map[r][c] == 1) return;
	}

	direction = 2;
	dfs({ pos.first + offsets[2].first, pos.second + offsets[2].second });
}

void dfs(pair<int, int> startPos)
{
	if (startPos.first == n && startPos.second == n)
	{
		result++;
		return;
		// 답을 찾은 경우
	}

	switch (direction)
	{
		case 0:
			MoveLeft(startPos);
			MoveCross(startPos);
			break;
		case 1:
			MoveDown(startPos);
			MoveCross(startPos);
			break;
		case 2:
			MoveLeft(startPos);
			MoveDown(startPos);
			MoveCross(startPos);
			break;
		default:
			break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	dfs({ 1, 2 });

	cout << result;
	return 0;
}