#include <iostream>
#include <queue>
using namespace std;

// r, c, h
int n, m, h;

const int maxSize = 100;
int arr[maxSize][maxSize][maxSize]; // h --> n --> m ������ ���ٰ� �����ϸ� ��

struct Vector3
{
public:
	int h, r, c;
};

const int offsetSize = 6;
Vector3 offset[offsetSize] =
{
	{0, 0, 1},
	{0, 0, -1},

	{0, 1, 0},
	{0, -1, 0},

	{1, 0, 0},
	{-1, 0, 0},
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;

	queue<Vector3> q;
	int leftCount = 0;

	for (int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int item;
				cin >> item;

				if (item == 1)
				{
					q.push({i, j, k}); // h, r, c
				}
				else if (item == 0)
				{
					leftCount++; // ���� ���� �丶���� ������ ���ش�.
				}

				arr[i][j][k] = item;
			}
		}
	}

	if (leftCount == 0) // ��� �丶�䰡 �;��ִ� ���
	{
		cout << 0;
		return 0;
	}

	while (q.empty() == false)
	{
		Vector3 pos = q.front();
		q.pop();

		int originItem = arr[pos.h][pos.r][pos.c]; // ����

		for (int i = 0; i < offsetSize; i++)
		{
			Vector3 newPos = { pos.h + offset[i].h, pos.r + offset[i].r, pos.c + offset[i].c };
			if (newPos.r < 0 || newPos.r >= n || newPos.c < 0 || newPos.c >= m || newPos.h < 0 || newPos.h >= h) continue; // ���� üũ

			int item = arr[newPos.h][newPos.r][newPos.c]; // ����
			if (item >= 1 || item == -1) continue; // �Ͱų� ���� ���� �ǳʶڴ�.

			leftCount--;
			if (leftCount == 0)
			{
				cout << originItem;
				return 0;
			}

			arr[newPos.h][newPos.r][newPos.c] = originItem + 1; // ���� ���� �丶�䰡 �ִ� ��� 1�� �������ش�.
			q.push(newPos);
		}
	}

	cout << -1;
	return 0;
}