#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

const int mapSize = 20;
int map[mapSize][mapSize];

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

template<typename T>
class Queue
{
public:
	void Push(T item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	T Front()
	{
		return _list.front();
	}

private:
	list<T> _list;
};


vector<pair<int, int>> ReturnClosePos(pair<int, int> pos, int n)
{
	vector<pair<int, int>> closePoints;

	for (int i = 0; i < offsetSize; i++)
	{
		int x = pos.first + offsets[i].first;
		int y = pos.second + offsets[i].second;

		if (x < 0 || x >= n || y < 0 || y >= n) continue;

		closePoints.push_back({ x, y });
	}

	return closePoints;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int sharkSize = 2;
	int level = 0;
	int time = 0;

	pair<int, int> startPos;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int item;
			cin >> item;

			if (item == 9) startPos = { j, i };
			map[i][j] = item;
		}
	}

	bool alreadyVisit[20][20]{ false };

	while (1)
	{
		bool visit[20][20]{false};

		Queue<pair<int, int>> queue;
		queue.Push(startPos);

		visit[startPos.second][startPos.first] = true;
		alreadyVisit[startPos.second][startPos.first] = true;

		int queueSize = queue.Size();

		vector<pair<int, int>> eatPos;
		int currentMoveTime = 0;

		while (queue.IsEmpty() == false)
		{
			for (int j = 0; j < queueSize; j++)
			{
				pair<int, int> pos = queue.Front();
				queue.Pop();

				vector<pair<int, int>> points = ReturnClosePos(pos, n);
				for (int i = 0; i < points.size(); i++)
				{
					int item = map[points[i].second][points[i].first];
					if (item != 9 && item > sharkSize) continue;

					if (visit[points[i].second][points[i].first] == true) continue;

					visit[points[i].second][points[i].first] = true;

					if (alreadyVisit[points[i].second][points[i].first] == false)
					{
						if (item > 0 && item < sharkSize)
						{
							eatPos.push_back(points[i]);
						}
					}

					queue.Push(points[i]);
				}
			}

			queueSize = queue.Size();

			currentMoveTime++;
			if (eatPos.size() > 0) break;
		}

		// 이 경우는 queue에 원소가 없는 경우임
		if (queue.IsEmpty() && eatPos.size() == 0) break;

		time += currentMoveTime;

		sort(eatPos.begin(), eatPos.end(), compare);
		startPos = eatPos[0];

		level++;
		if (level == sharkSize)
		{
			sharkSize++;
			level = 0;
		}
	}

	cout << time;

	return 0;
}