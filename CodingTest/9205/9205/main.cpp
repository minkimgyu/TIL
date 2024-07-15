#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<pair<int, int>> ReturnClosePoints(
	pair<int, int> pos,
	vector<pair<int, int>> points)
{
	vector<pair<int, int>> targetPoints;

	for (int i = 0; i < points.size(); i++)
	{
		pair<int, int> point = points[i];

		int xDistance = abs(point.first - pos.first);
		int yDistance = abs(point.second - pos.second);

		// 20 * 50 이라서 1000m마다 보충해야함
		// 즉 1000m 이상 이동 불가능함
		int distance = xDistance + yDistance;
		if (distance > 1000) continue;

		targetPoints.push_back({ point.first, point.second });
	}

	return targetPoints;
}

// 맥주를 넣는 개수를 잘못 이해함

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int beerCount = 20;
		map<pair<int, int >, bool> visit;

		vector<pair<int, int>> points;
		for (int j = 0; j < n + 2; j++)
		{
			int start, end;
			cin >> start >> end;
			points.push_back({ start, end });
		}

		queue<pair<int, int>> queue;
		queue.push(points[0]);
		visit[points[0]] = true;

		bool canExit = false;

		while (queue.empty() == false)
		{
			pair<int, int> point = queue.front();
			queue.pop();

			vector<pair<int, int>> targetPointDatas = ReturnClosePoints(point, points);
			for (int i = 0; i < targetPointDatas.size(); i++)
			{
				pair<int, int> targetPoint = targetPointDatas[i];
				if (visit[targetPoint] == true) continue;

				if (targetPoint.first == points[n + 1].first && targetPoint.second == points[n + 1].second)
				{
					canExit = true;
					break;
				}

				visit[targetPoint] = true;
				queue.push(targetPoint);
			}

			if (canExit) break;
		}

		if (canExit == true) cout << "happy";
		else cout << "sad";

		if(i != t - 1) cout << '\n';
	}

	return 0;
}