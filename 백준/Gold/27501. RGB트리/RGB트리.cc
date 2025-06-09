#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 500000 + 5;
vector<int> connections[maxSize];

bool visit[maxSize];
int dp[maxSize][3];
int color[maxSize][3];

int trackArr[maxSize];

void dfs(int index)
{
	visit[index] = true;
	dp[index][0] = color[index][0];
	dp[index][1] = color[index][1];
	dp[index][2] = color[index][2];

	for (int i = 0; i < connections[index].size(); i++)
	{
		int goIndex = connections[index][i];
		if (visit[goIndex] == true) continue;

		dfs(goIndex);

		dp[index][0] += max(dp[goIndex][1], dp[goIndex][2]);
		dp[index][1] += max(dp[goIndex][0], dp[goIndex][2]);
		dp[index][2] += max(dp[goIndex][0], dp[goIndex][1]);
	}
}

void track(int index, int beforeColor)
{
	visit[index] = true;

	for (int i = 0; i < connections[index].size(); i++)
	{
		int goIndex = connections[index][i];
		if (visit[goIndex] == true) continue;

		// 더 큰 값을 출력해준다. -> 점화식을 역으로 따라가면 된다.
		switch (beforeColor)
		{
			case 0:
				if (dp[goIndex][1] >= dp[goIndex][2]) trackArr[goIndex] = 1;
				else trackArr[goIndex] = 2;
				break;
			case 1:
				if (dp[goIndex][0] >= dp[goIndex][2]) trackArr[goIndex] = 0;
				else trackArr[goIndex] = 2;
				break;
			case 2:
				if (dp[goIndex][0] >= dp[goIndex][1]) trackArr[goIndex] = 0;
				else trackArr[goIndex] = 1;
				break;
		}

		track(goIndex, trackArr[goIndex]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		connections[start].push_back(end);
		connections[end].push_back(start);
	}

	for (int i = 1; i <= n; i++) trackArr[i] = -1;

	for (int i = 1; i <= n; i++)
	{
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}

	dfs(1);
	cout << max(max(dp[1][0], dp[1][1]), dp[1][2]) << '\n';

	for (int i = 1; i <= n; i++) visit[i] = false;

	if (dp[1][0] >= max(dp[1][1], dp[1][2]))
	{
		cout << 'R';
		track(1, 0);
	}
	else if (dp[1][1] >= max(dp[1][0], dp[1][2]))
	{
		cout << 'G';
		track(1, 1);
	}
	else if (dp[1][2] >= max(dp[1][0], dp[1][1]))
	{
		cout << 'B';
		track(1, 2);
	}

	for (int i = 2; i <= n; i++)
	{
		switch (trackArr[i])
		{
			case 0:
				cout << 'R';
				break;
			case 1:
				cout << 'G';
				break;
			case 2:
				cout << 'B';
				break;
		}
	}
	
	return 0;
}