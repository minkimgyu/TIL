#include <iostream>
#include <queue>
using namespace std;

const int maxSize = 50 + 5;
int arr[maxSize][maxSize];
bool visit[maxSize][maxSize];

const int nearPointCount = 8;
pair<int, int> nearPoints[nearPointCount] = { {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int c, r;
		cin >> c >> r;
		if (r == 0 && c == 0) break;

		// 입력 받기
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> arr[i][j];
			}
		}

		int result = 0;
		queue<pair<int, int>> q;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (visit[i][j] == true) continue;
				if (arr[i][j] == 0) continue;

				q.push({ i, j });
				visit[i][j] = true;

				result++;

				while (q.empty() == false)
				{
					pair<int, int> point = q.front();
					q.pop();

					for (int k = 0; k < nearPointCount; k++)
					{
						pair<int, int> nearPoint = { point.first + nearPoints[k].first, point.second + nearPoints[k].second };

						if (nearPoint.first < 0 || nearPoint.second < 0 || nearPoint.first >= r || nearPoint.second >= c) continue;

						if (arr[nearPoint.first][nearPoint.second] == 0) continue; // 바다면 continue
						if (visit[nearPoint.first][nearPoint.second] == true) continue; // 이미 방문했다면 continue

						visit[nearPoint.first][nearPoint.second] = true;
						q.push({ nearPoint.first, nearPoint.second });
					}
				}
			}
		}

		cout << result << '\n';

		// 초기화 진행
		for (int i = 0; i < maxSize; i++)
		{
			for (int j = 0; j < maxSize; j++)
			{
				arr[i][j] = 0;
				visit[i][j] = false;
			}
		}
	}

	return 0;
}