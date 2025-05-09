#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 100 + 5;
int arr[maxSize][maxSize];

bool visit[maxSize][maxSize][4];
int mirror[maxSize][maxSize][4];

vector<pair<int, int>> points;
queue<pair<pair<int, int>, pair<int, int>>> q;

int w, h;

const int maxDirection = 4;
pair<int, int> nearPoints[maxDirection] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool OutOfRange(pair<int, int> point)
{
	return point.first < 0 || point.second < 0 || point.first >= h || point.second >= w;
}

int minMirrorCount = maxSize * maxSize;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> w >> h;

	if (w == 1 && h == 1)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			char item;
			cin >> item;

			mirror[i][j][0] = maxSize * maxSize;
			mirror[i][j][1] = maxSize * maxSize;
			mirror[i][j][2] = maxSize * maxSize;
			mirror[i][j][3] = maxSize * maxSize;

			switch (item)
			{
				case '.':
					arr[i][j] = 0;
					break;
				case '*':
					arr[i][j] = 1; // 5
					break;
				case 'C':

					if (points.empty() == true) arr[i][j] = 2;
					else arr[i][j] = 3;
					
					points.push_back({ i, j });
					break;
				default:
					break;
			}
		}
	}


	q.push({ points[0], {-1, 0} });

	for (int i = 0; i < 4; i++)
	{
		mirror[points[0].first][points[0].second][i] = 0;
		visit[points[0].first][points[0].second][i] = 0;
	}

	while (q.empty() == false)
	{
		pair<int, int> front = q.front().first; 
		pair<int, int> info = q.front().second; // 방향, 곡선 개수

		q.pop();

		for (int i = 0; i < maxDirection; i++)
		{
			pair<int, int> nearPoint = { front.first + nearPoints[i].first, front.second + nearPoints[i].second };
			if (OutOfRange(nearPoint) == true) continue;

			if (arr[nearPoint.first][nearPoint.second] == 1) continue;
			//if (visit[nearPoint.first][nearPoint.second][i] == true) continue;

			int curveCount = info.second;
			if (info.first != i) curveCount += 1;

			if (mirror[nearPoint.first][nearPoint.second][i] > curveCount)
			{
				visit[nearPoint.first][nearPoint.second][i] = true;
				mirror[nearPoint.first][nearPoint.second][i] = curveCount;
				q.push({ nearPoint, {i, curveCount} }); // 방향이 다른 경우
			}
		}
	}

	int minMirror = maxSize * maxSize;
	for (int i = 0; i < 4; i++)
	{
		if (visit[points[1].first][points[1].second][i] == false) continue;
		minMirror = min(minMirror, mirror[points[1].first][points[1].second][i]);
	}

	cout << minMirror - 1;
	return 0;
}