#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 500 + 5;
int indegree[maxSize]; // 진입 차수
int cost[maxSize]; // cost

int maxCost[maxSize]; // cost
vector<int> connections[maxSize]; // moveTo

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i]; // cost 받기

		while(1)
		{
			int beforeIdx;
			cin >> beforeIdx;

			if (beforeIdx == -1) break;

			indegree[i] += 1;
			connections[beforeIdx].push_back(i);
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			maxCost[i] = cost[i]; // cost 넣어주기
		}
	}

	while (q.empty() == false)
	{
		int currentIdx = q.front();
		q.pop();

		for (int i = 0; i < connections[currentIdx].size(); i++)
		{
			int nxtIdx = connections[currentIdx][i];
			indegree[nxtIdx]--;
			
			// maxCost 업데이트
			maxCost[nxtIdx] = max(maxCost[nxtIdx], maxCost[currentIdx] + cost[nxtIdx]);

			// 차수가 0이 되면 q에 추가
			if (indegree[nxtIdx] == 0) q.push(nxtIdx);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << maxCost[i];
		if (i != n) cout << '\n';
	}

	return 0;
}