#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int t, n;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<pair<int, int>> points;
		pair<int, int> startPoint;
		pair<int, int> endPoint;

		cin >> n;
		cin >> startPoint.first >> startPoint.second;

		for (int j = 0; j < n; j++)
		{
			pair<int, int> point;
			cin >> point.first >> point.second;
			points.push_back(point);
		}

		cin >> endPoint.first >> endPoint.second;
		points.push_back(endPoint);

		bool canClear = false;
		map<int, bool> visit;
		queue<pair<int, int>> q;
		q.push(startPoint);

		while (q.empty() == false)
		{
			pair<int, int> front = q.front();
			q.pop();

			for (int k = 0; k < points.size(); k++)
			{
				int distance = abs(front.first - points[k].first) + abs(front.second - points[k].second);
				if (distance > 1000) continue; // 20 * 50 �� 1000m ���� �� ���� ���ž��Ѵ�. �� 1000m���� �� �� �ִ�.
				if (visit[k] == true) continue; // ������ �湮�ߴٸ� �ǳʶٱ�

				if (points[k] == endPoint)
				{
					canClear = true;
					break;
				}

				visit[k] = true;
				q.push(points[k]);
			}

			if (canClear == true) break;
		}

		if (canClear == true)
		{
			cout << "happy";
		}
		else
		{
			cout << "sad";
		}

		if (i != t - 1) cout << '\n';
	}

	return 0;
}