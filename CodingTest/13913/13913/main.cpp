#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[100000]{false, };
int dp[100001]{0, };

int main()
{
	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> queue;
	queue.push({ n, 0 });

	int time = 0;
	vector<int> route;

	while (queue.empty() == false)
	{
		pair<int, int> item = queue.front();
		queue.pop();

		if (item.first == k)
		{
			time = item.second;
			break;
		}

		int closePoints[3] = { item.first - 1, item.first + 1, item.first * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (closePoints[i] < 0 || closePoints[i] > 100000) continue;
			if (visit[closePoints[i]] == true) continue;

			visit[closePoints[i]] = true;
			dp[closePoints[i]] = item.first;

			int duration = item.second;
			duration += 1;
			queue.push({ closePoints[i], duration });
		}
	}

	route.push_back(k);
	while (route.back() != n)
	{
		int back = route.back();
		route.push_back(dp[back]);
	}

	cout << time << '\n';
	for (int i = route.size() - 1; i > -1; i--)
	{
		cout << route[i];
		if (i != 0) cout << " ";
	}

	return 0;
}