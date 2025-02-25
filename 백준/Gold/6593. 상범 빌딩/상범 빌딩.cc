#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int maxSize = 30;
char arr[maxSize][maxSize][maxSize];
int visit[maxSize][maxSize][maxSize];

struct Vector3
{
public:
	int l, r, c;
};

const int offsetSize = 6;
Vector3 offset[offsetSize] =
{
	{1, 0, 0},
	{-1, 0, 0},

	{0, 1, 0},
	{0, -1, 0},

	{0, 0, 1},
	{0, 0, -1},
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		cin.ignore();

		queue<Vector3> q;
		Vector3 endPoint;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				string line;
				getline(cin, line);

				for (int k = 0; k < c; k++)
				{
					char item = line[k];
					if (item == 'S')
					{
						q.push({ i, j, k });
					}
					else if (item == 'E')
					{
						endPoint = { i, j, k };
					}

					arr[i][j][k] = item;
				}
			}
			cin.ignore();
		}

		bool nowClear = false;

		while (q.empty() == false)
		{
			Vector3 front = q.front();
			int originPassedTime = visit[front.l][front.r][front.c];

			q.pop();

			for (int i = 0; i < offsetSize; i++)
			{
				Vector3 pos = { front.l + offset[i].l, front.r + offset[i].r, front.c + offset[i].c };
				if (pos.l < 0 || pos.l >= l || pos.r < 0 || pos.r >= r || pos.c < 0 || pos.c >= c) continue;

				char item = arr[pos.l][pos.r][pos.c];
				if (item == '#' || item == 'S') continue; // 막혔거나 시작 포인트인 경우 건너뛰기
				if (visit[pos.l][pos.r][pos.c] > 0) continue; // 이미 방문한 지점이면 건너뛰기

				if (item == 'E') // 목적지에 도달한 경우
				{
					nowClear = true;
					cout << "Escaped in " << originPassedTime + 1 << " minute(s).\n";
					break;
				}

				visit[pos.l][pos.r][pos.c] = originPassedTime + 1;
				q.push(pos);
			}

			if (nowClear == true) break;
		}

		if (nowClear == false)
		{
			cout << "Trapped!" << '\n'; // 도달하지 못한 경우
		}

		// 방문 배열 초기화
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				for (int k = 0; k < maxSize; k++)
				{
					visit[i][j][k] = 0;
				}
			}
		}
	}

	return 0;
}