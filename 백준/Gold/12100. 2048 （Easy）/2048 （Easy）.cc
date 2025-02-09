#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 20 + 5;
int board1[maxSize][maxSize];

int board2[maxSize][maxSize]; // 가변적으로 사용할 보드

int n;
int result = 0;

void pushUp()
{
	int tilted[maxSize][maxSize];

	// 초기화
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			tilted[i][j] = 0;
		}
	}

	for (int i = 0; i < maxSize; i++)
	{
		int idx = maxSize - 1;

		for (int j = maxSize - 1; j > -1; j--)
		{
			if (board2[j][i] == 0) continue;

			if (tilted[idx][i] == 0) // 비어있는 경우
			{
				tilted[idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
			else if (tilted[idx][i] == board2[j][i]) // 값이 같은 경우
			{
				tilted[idx--][i] *= 2; // idx--을 통해 겹치지 않게 한다.

				result = max(result, board2[j][i] * 2);
			}
			else
			{
				tilted[--idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
		}
	}

	// copy해서 board2로 옮겨준다.
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			board2[i][j] = tilted[i][j];
		}
	}
}

void pushRight()
{
	int tilted[maxSize][maxSize];

	// 초기화
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			tilted[i][j] = 0;
		}
	}

	for (int i = 0; i < maxSize; i++)
	{
		int idx = maxSize - 1;

		for (int j = maxSize - 1; j > -1; j--)
		{
			if (board2[i][j] == 0) continue;

			if (tilted[i][idx] == 0) // 비어있는 경우
			{
				tilted[i][idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
			else if (tilted[i][idx] == board2[i][j]) // 값이 같은 경우
			{
				tilted[i][idx--] *= 2; // idx--을 통해 겹치지 않게 한다.

				result = max(result, board2[i][j] * 2);
			}
			else
			{
				tilted[i][--idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
		}
	}

	// copy해서 board2로 옮겨준다.
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			board2[i][j] = tilted[i][j];
		}
	}
}

void pushDown()
{
	int tilted[maxSize][maxSize];

	// 초기화
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			tilted[i][j] = 0;
		}
	}

	for (int i = 0; i < maxSize; i++)
	{
		int idx = 0;

		for (int j = 0; j < maxSize; j++)
		{
			if (board2[j][i] == 0) continue;

			if (tilted[idx][i] == 0) // 비어있는 경우
			{
				tilted[idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
			else if (tilted[idx][i] == board2[j][i]) // 값이 같은 경우
			{
				tilted[idx++][i] *= 2; // idx++을 통해 겹치지 않게 한다.

				result = max(result, board2[j][i] * 2);
			}
			else
			{
				tilted[++idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
		}
	}

	// copy해서 board2로 옮겨준다.
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			board2[i][j] = tilted[i][j];
		}
	}
}

void pushLeft()
{
	int tilted[maxSize][maxSize];

	// 초기화
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			tilted[i][j] = 0;
		}
	}

	for (int i = 0; i < maxSize; i++)
	{
		int idx = 0;

		for (int j = 0; j < maxSize; j++)
		{
			if (board2[i][j] == 0) continue;

			if (tilted[i][idx] == 0) // 비어있는 경우
			{
				tilted[i][idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
			else if (tilted[i][idx] == board2[i][j]) // 값이 같은 경우
			{
				tilted[i][idx++] *= 2; // idx++을 통해 겹치지 않게 한다.

				result = max(result, board2[i][j] * 2);
			}
			else
			{
				tilted[i][++idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
		}
	}

	// copy해서 board2로 옮겨준다.
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			board2[i][j] = tilted[i][j];
		}
	}
}

void tilt(int dir)
{
	switch (dir)
	{
		case 0:
			pushUp();
			break;
		case 1:
			pushRight();
			break;
		case 2:
			pushDown();
			break;
		case 3:
			pushLeft();
			break;
	}
}

void per()
{
	for (int i = 0; i < 1024; i++)
	{
		// 보드 copy
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				board2[i][j] = board1[i][j];
			}
		}

		int brute = i;

		for (int j = 0; j < 5; j++)
		{
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board1[i][j];
		}
	}

	per();
	cout << result;

	return 0;
}