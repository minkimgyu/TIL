#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[100000];

vector<pair<int, int>> ReturnPassPoint(pair<int, int> data)
{
	vector<pair<int, int>> result;
	int passPoints[3] = { data.first - 1, data.first + 1, data.first * 2 };

	for (int i = 0; i < 3; i++)
	{
		if (passPoints[i] > 100000 || passPoints[i] < 0) continue;
		result.push_back({ passPoints[i], data.second });
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	int result = -1;

	queue<pair<int, int>> queue;
	queue.push({ n, 0 });

	while (queue.empty() == false)
	{
		pair<int, int> item = queue.front();
		queue.pop();

		if (item.first == k)
		{
			result = item.second;
			break;
		}

		vector<pair<int, int>> passPoints = ReturnPassPoint(item);
		for (int i = 0; i < passPoints.size(); i++)
		{
			if (visit[passPoints[i].first] == true) continue;

			passPoints[i].second += 1;

			visit[passPoints[i].first] = true;
			queue.push(passPoints[i]);
		}
	}

	cout << result;
	return 0;
}