#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visit[1000000];

vector<pair<int, int>> ReturnCloseFloor(pair<int, int> item, int U, int D, int max)
{
	vector<pair<int, int>> results;

	int offset[2] = { item.first + U, item.first - D };
	for (int i = 0; i < 2; i++)
	{
		if (offset[i] > max || offset[i] <= 0) continue;
		results.push_back({ offset[i], item.second });
	}

	return results;
}

int main()
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	int result = 0;

	queue<pair<int, int>> queue;
	queue.push({ S, 0 });

	while (queue.empty() == false)
	{
		pair<int, int> item = queue.front();
		queue.pop();

		if (item.first == G)
		{
			cout << item.second;
			return 0;
		}

		vector<pair<int, int>> closeFloors = ReturnCloseFloor(item, U, D, F);
		for (int i = 0; i < closeFloors.size(); i++)
		{
			if (visit[closeFloors[i].first] == true) continue;

			closeFloors[i].second += 1;
			visit[closeFloors[i].first] = true;
			queue.push(closeFloors[i]);
		}
	}

	cout << "use the stairs";

	return 0;
}