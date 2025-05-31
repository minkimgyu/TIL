#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 10000 + 5;
vector<int> connections[maxSize];
int indegree[maxSize];
int timeCost[maxSize];
bool visit[maxSize];
int dp[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int connectionCount = 0;
		cin >> timeCost[i] >> connectionCount;
		for (int j = 0; j < connectionCount; j++)
		{
			int nxt;
			cin >> nxt;

			connections[nxt].push_back(i);
			indegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0 && visit[i] == false)
		{
			q.push(i);
			visit[i] = true;
			dp[i] = timeCost[i];
		}
	}

	while (q.empty() == false)
	{
		int front = q.front(); q.pop();

		for (int i = 0; i < connections[front].size(); i++)
		{
			int nxt = connections[front][i];
			indegree[nxt]--;
			dp[nxt] = max(dp[nxt], dp[front] + timeCost[nxt]); // 진입한 경우 max로 최대 값 설정하기
		}

		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0 && visit[i] == false)
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}
