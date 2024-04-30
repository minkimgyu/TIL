#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
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

	T Back()
	{
		return _list.back();
	}

private:
	list<T> _list;
};

const int closeCnt = 4;
pair<int, int>* closePoints = new pair<int, int>[closeCnt]
{ 
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

const int horseCnt = 8;
pair<int, int>* horsePoints = new pair<int, int>[horseCnt]
{ 
	{ 1, 2 }, { -1, 2 }, { 1, -2 }, { -1, -2 },
	{ 2, 1 }, { 2, -1 }, { -2, 1 }, {-2, -1 } 
};

vector<pair<int, int>> ReturnClosePoint(pair<int, int> pos, pair<int, int>* closeOffset, int n, int w, int h)
{
	vector<pair<int, int>> closePoints;

	for (int i = 0; i < n; i++)
	{
		pair<int, int> closePoint;
		closePoint.first = pos.first + closeOffset[i].first;
		closePoint.second = pos.second + closeOffset[i].second;

		if (closePoint.first < 0 || closePoint.first >= w || closePoint.second < 0 || closePoint.second >= h) continue;

		closePoints.push_back(closePoint);
	}

	return closePoints;
}

const int maxSize = 200;
int map[maxSize][maxSize];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 0;
	cin >> k;

	int w, h;
	cin >> w >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
		}
	}

	int visit = 1;
	Queue<pair<int, int>> queue;

	pair<int, int> start;
	start.first = 0;
	start.second = 0;
	map[start.second][start.first] = 1;

	queue.Push(start);

	while (queue.Size() > 0)
	{
		int queueSize = queue.Size();
		Queue<pair<int, int>> storedQueue = queue;

		for (int t = 0; t < queueSize; t++)
		{
			pair<int, int> pos = queue.Front();
			queue.Pop();

			int currentValue = map[pos.second][pos.first];

			vector<pair<int, int>> nearPoints = ReturnClosePoint(pos, closePoints, closeCnt, w, h);
			int nearPointsCnt = nearPoints.size();

			vector<pair<int, int>> nearHorsePoints = ReturnClosePoint(pos, horsePoints, horseCnt, w, h);
			int nearHorsePointsCnt = nearHorsePoints.size();

			for (int i = 0; i < nearPointsCnt; i++)
			{
				int value = map[nearPoints[i].second][nearPoints[i].first];
				if (value > 0) continue;

				// 종료 조건
				if (nearPoints[i].first == w - 1 && nearPoints[i].second == h - 1)
				{
					cout << currentValue;
					return 0;
				}

				map[nearPoints[i].second][nearPoints[i].first] = currentValue + 1;
				queue.Push(nearPoints[i]);
			}
			 
			if (k <= 0) continue;

			for (int i = 0; i < nearHorsePointsCnt; i++)
			{
				// 종료 조건
				if (nearHorsePoints[i].first == w - 1 && nearHorsePoints[i].second == h - 1)
				{
					cout << currentValue;
					return 0;
				}
			}
		}

		if (queue.Size() > 0) continue;
		if (k <= 0) break; // 말 움직임을 진행하면 안 됨

		queue = storedQueue;

		for (int t = 0; t < queueSize; t++)
		{
			pair<int, int> pos = queue.Front();
			queue.Pop();

			int currentValue = map[pos.second][pos.first];

			vector<pair<int, int>> nearPoints = ReturnClosePoint(pos, horsePoints, horseCnt, w, h);
			int nearPointsCnt = nearPoints.size();

			for (int i = 0; i < nearPointsCnt; i++)
			{
				int value = map[nearPoints[i].second][nearPoints[i].first];
				if (value > 0) continue;

				// 종료 조건
				if (nearPoints[i].first == w - 1 && nearPoints[i].second == h - 1)
				{
					cout << currentValue;
					return 0;
				}

				map[nearPoints[i].second][nearPoints[i].first] = currentValue + 1;
				queue.Push(nearPoints[i]);
			}
		}

		// queue에 무언가 노드가 들어온 경우를 뜻함
		if (queue.Size() > 0) k--;
	}

	cout << -1;
	return 0;
}