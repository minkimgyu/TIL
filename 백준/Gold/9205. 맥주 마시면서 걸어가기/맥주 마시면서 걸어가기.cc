#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 범위가 1000보다 작아야 함

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int pointCount;

		queue<pair<int, int>> pointQueue;
		vector<pair<int, int>> points;

		bool visit[100];
		for (int j = 0; j < 100; j++) visit[j] = false;

		cin >> pointCount;

		for (int j = 0; j < pointCount + 2; j++)
		{
			int x, y;
			cin >> x >> y;

			points.push_back({ x , y });
		}

		pointQueue.push(points[0]);
		visit[0] = true;

		bool isClear = false;
		while (pointQueue.empty() == false)
		{
			pair<int, int> point = pointQueue.front();
			pointQueue.pop();

			for (int j = 0; j < pointCount + 2; j++)
			{
				if (visit[j] == true) continue;

				int distance = abs(point.first - points[j].first) + abs(point.second - points[j].second);
				if (distance > 1000) continue;

				if (j == pointCount + 1)
				{
					cout << "happy";
					isClear = true;
					break;
				}

				pointQueue.push(points[j]);
				visit[j] = true;
			}

			if (isClear == true) break;
		}

		if (isClear == false) cout << "sad";
		if (i != t - 1) cout << '\n';
	}
	 

	return 0;
}