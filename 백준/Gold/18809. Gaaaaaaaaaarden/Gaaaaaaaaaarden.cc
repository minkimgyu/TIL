#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int g, r;

const int maxSize = 50 + 5;
int arrMap[maxSize][maxSize];

const int maxPickCount = 5 + 5;
int pickGArr[maxPickCount];
int pickRArr[maxPickCount];

vector<pair<int, int>> twoLands;
pair<int, int> nearPos[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int result = 0;

vector<pair<int, int>> greens;
vector<pair<int, int>> reds;

bool InRange(pair<int, int> pos)
{
	if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m) return false;
	return true;
}

pair<int, int> bfsMap[maxSize][maxSize];

void bfs()
{
	int flowerCount = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			bfsMap[i][j] = { 0, arrMap[i][j] }; // 시간, 색상
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q; // 시간, 색상, 위치
	for (int i = 0; i < reds.size(); i++)
	{
		q.push({ {0, 3}, reds[i] }); // 레드 배양액 위치
		bfsMap[reds[i].first][reds[i].second] = { 0, 3 };
	}

	for (int i = 0; i < greens.size(); i++)
	{
		q.push({ {0, 4}, greens[i] }); // 그린 배양액 위치
		bfsMap[greens[i].first][greens[i].second] = { 0, 4 };
	}
	// 꽃은 5

	while (q.empty() == false)
	{
		pair<pair<int, int>, pair<int, int>> top = q.front(); q.pop();
		if (bfsMap[top.second.first][top.second.second].second == 5) continue; // 자신의 위치가 꽃으로 바뀐 경우 continue;

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> nearPoint = { top.second.first + nearPos[i].first, top.second.second + nearPos[i].second };
			if (InRange(nearPoint) == false) continue;
			if (bfsMap[nearPoint.first][nearPoint.second].second == 0) continue; // 호수면 continue
			if (bfsMap[nearPoint.first][nearPoint.second].second == 5) continue; // 꽃이면 continue

			if (bfsMap[nearPoint.first][nearPoint.second].second == top.first.second) continue; // 같은 배양액이면 continue


			if ((bfsMap[nearPoint.first][nearPoint.second].second == 3 && top.first.second == 4) ||
				bfsMap[nearPoint.first][nearPoint.second].second == 4 && top.first.second == 3) // 서로 다른 배양액을 만날 경우
			{
				// top에서 +1 적용한 값이 윈래 map의 도달 시간과 같아야함
				if (top.first.first + 1 == bfsMap[nearPoint.first][nearPoint.second].first) // 도달한 시각이 같다면 꽃 생성
				{
					bfsMap[nearPoint.first][nearPoint.second] = { bfsMap[nearPoint.first][nearPoint.second].first, 5}; // 꽃 넣기
					flowerCount++;
					result = max(result, flowerCount);
				}
			}
			else // 새로운 위치로 이동
			{
				bfsMap[nearPoint.first][nearPoint.second] = { top.first.first + 1, top.first.second };
				q.push({ {top.first.first + 1, top.first.second}, nearPoint }); // 시간 1 올려주기
			}
		}
	}
}

int twoLandSize;

void pickR(int itemCount, int count)
{
	if (itemCount == count)
	{
		/*cout << '\n';
		for (int i = 0; i < g; i++)
		{
			cout << pickGArr[i] << " ";
		}
		cout << '\n';
		for (int i = 0; i < r; i++)
		{
			cout << pickRArr[i] << " ";
		}
		cout << '\n';*/

		greens.clear();
		reds.clear();

		for (int i = 0; i < g; i++)
		{
			greens.push_back(twoLands[pickGArr[i]]);
		}

		for (int i = 0; i < r; i++)
		{
			reds.push_back(twoLands[pickRArr[i]]);
		}

		bfs();
	}
	else
	{
		for (int i = 0; i < twoLandSize; i++)
		{
			// g에 포함되지 않는 경우만 뽑아야함
			bool pass = false;
			for (int j = 0; j < g; j++)
			{
				if (i == pickGArr[j])
				{
					pass = true;
					break;
				}
			}
			if (pass == true) continue;

			if (count > 0 && pickRArr[count - 1] >= i) continue;
			pickRArr[count] = i;
			pickR(itemCount, count + 1);
		}
	}
}

void pickG(int itemCount, int count)
{
	if (itemCount == count)
	{
		pickR(r, 0);
	}
	else
	{
		for (int i = 0; i < twoLandSize; i++)
		{
			if (count > 0 && pickGArr[count - 1] >= i) continue;
			pickGArr[count] = i;
			pickG(itemCount, count + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arrMap[i][j];
			if (arrMap[i][j] == 2) twoLands.push_back({ i, j });
		}
	}

	twoLandSize = twoLands.size();
	pickG(g, 0);
	cout << result;
	return 0;
}