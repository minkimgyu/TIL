#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 20 + 5;
int board1[maxSize][maxSize];

int board2[maxSize][maxSize]; // ���������� ����� ����

int n;
int result = 0;

void pushUp()
{
	int tilted[maxSize][maxSize];

	// �ʱ�ȭ
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

			if (tilted[idx][i] == 0) // ����ִ� ���
			{
				tilted[idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
			else if (tilted[idx][i] == board2[j][i]) // ���� ���� ���
			{
				tilted[idx--][i] *= 2; // idx--�� ���� ��ġ�� �ʰ� �Ѵ�.

				result = max(result, board2[j][i] * 2);
			}
			else
			{
				tilted[--idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
		}
	}

	// copy�ؼ� board2�� �Ű��ش�.
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

	// �ʱ�ȭ
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

			if (tilted[i][idx] == 0) // ����ִ� ���
			{
				tilted[i][idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
			else if (tilted[i][idx] == board2[i][j]) // ���� ���� ���
			{
				tilted[i][idx--] *= 2; // idx--�� ���� ��ġ�� �ʰ� �Ѵ�.

				result = max(result, board2[i][j] * 2);
			}
			else
			{
				tilted[i][--idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
		}
	}

	// copy�ؼ� board2�� �Ű��ش�.
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

	// �ʱ�ȭ
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

			if (tilted[idx][i] == 0) // ����ִ� ���
			{
				tilted[idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
			else if (tilted[idx][i] == board2[j][i]) // ���� ���� ���
			{
				tilted[idx++][i] *= 2; // idx++�� ���� ��ġ�� �ʰ� �Ѵ�.

				result = max(result, board2[j][i] * 2);
			}
			else
			{
				tilted[++idx][i] = board2[j][i];

				result = max(result, board2[j][i]);
			}
		}
	}

	// copy�ؼ� board2�� �Ű��ش�.
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

	// �ʱ�ȭ
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

			if (tilted[i][idx] == 0) // ����ִ� ���
			{
				tilted[i][idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
			else if (tilted[i][idx] == board2[i][j]) // ���� ���� ���
			{
				tilted[i][idx++] *= 2; // idx++�� ���� ��ġ�� �ʰ� �Ѵ�.

				result = max(result, board2[i][j] * 2);
			}
			else
			{
				tilted[i][++idx] = board2[i][j];

				result = max(result, board2[i][j]);
			}
		}
	}

	// copy�ؼ� board2�� �Ű��ش�.
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
		// ���� copy
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

	// 1 0 0 0 0 0 --> �̷� ������ ����
	// �̰ź��� ���� �����̹Ƿ� 1 1 1 1 1 �̴�.
	// 
	// 1 0 0 1 1
	// 0 0 0 1 0
	// 0 0 1 0 0
	// 0 1 0 0 0

	//for (int i = 0; i < (1 << 5); i++)
	//{
	//	// ���� copy
	//	for (int i = 0; i < maxSize; i++)
	//	{
	//		for (int j = 0; j < maxSize; j++)
	//		{
	//			board2[i][j] = board1[i][j];
	//		}
	//	}

	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (i & (1 << j))
	//		{
	//			cout << j << " ";
	//			tilt(j);
	//		}
	//	}

	//	cout << '\n';
	//}

	// �ߺ� ������ �Ұ���
	// ��ó�� �ڸ����� ���� �����ؾ���
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