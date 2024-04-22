#include <iostream>
using namespace std;

const int maxSize = 10;
int arr[maxSize][maxSize];
bool visit[maxSize]{ false };

void dfs(int current, int next, int cost, int cnt, int* min)
{
	visit[next] = true;
	cost += arr[current][next];

	int visitCnt = 0;
	for (int i = 0; i < cnt; i++)
	{
		// 이미 방문했거나 
		if (visit[i] == true)
		{
			visitCnt++;
			continue;
		}

		// 방문할 도시까지의 비용이 0인 경우 continue
		// 이 경우는 제외해줘야 한다. --> visitCnt 이거 안 올림
		if (arr[next][i] == 0)
		{
			continue;
		}

		dfs(next, i, cost, cnt, min);
	}

	if (visitCnt == cnt && arr[next][0] != 0) // 모든 지점을 전부 방문한 경우에 진행
	{
		cost += arr[next][0];
		if (*min > cost) *min = cost;
	}

	visit[next] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int min = 1e9;
	dfs(0, 0, 0, n, &min);

	if (min == 1e9) min = 0;
	cout << min;
	return 0;
}