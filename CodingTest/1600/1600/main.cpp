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

const int monkeyWayCnt = 4;
pair<int, int>* monkeyPoints = new pair<int, int>[monkeyWayCnt]
{ 
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

const int horseWayCnt = 8;
pair<int, int>* horsePoints = new pair<int, int>[horseWayCnt]
{ 
	{ 1, 2 }, { -1, 2 }, { 1, -2 }, { -1, -2 },
	{ 2, 1 }, { 2, -1 }, { -2, 1 }, {-2, -1 } 
};

const int maxSize = 200;
const int maxhorstMoveCnt = 31;
int map[maxhorstMoveCnt][maxSize][maxSize];

struct Monkey
{
public:
	pair<int, int> _pos;
	int moveCnt;
	int horseCnt;
};

void MoveWay(Queue<Monkey>* queue, Monkey monkey, pair<int, int>* closeOffset, int n, int w, int h, bool isHorse)
{
	for (int i = 0; i < n; i++)
	{
		Monkey nearPoint;
		nearPoint._pos.first = monkey._pos.first + closeOffset[i].first;
		nearPoint._pos.second = monkey._pos.second + closeOffset[i].second;

		if (nearPoint._pos.first >= 0 && nearPoint._pos.first < w && nearPoint._pos.second >= 0 && nearPoint._pos.second < h)
		{
			nearPoint.moveCnt = monkey.moveCnt + 1;

			if(isHorse) nearPoint.horseCnt = monkey.horseCnt - 1;
			else nearPoint.horseCnt = monkey.horseCnt;
			

			if (map[nearPoint.horseCnt][nearPoint._pos.second][nearPoint._pos.first] > 0) continue;

			map[nearPoint.horseCnt][nearPoint._pos.second][nearPoint._pos.first] = nearPoint.moveCnt;
			queue->Push(nearPoint);
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k = 0;
	cin >> k;

	int w, h;
	cin >> w >> h;

	
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int item;
			cin >> item;

			for (int z = 0; z <= k; z++)
			{
				map[z][y][x] = item;
			}
		}
	}
	
	Queue<Monkey> queue;

	Monkey start;
	start._pos.first = 0;
	start._pos.second = 0;
	start.moveCnt = 1;
	start.horseCnt = k;

	map[k][start._pos.second][start._pos.first] = start.moveCnt;
	queue.Push(start);

	while (queue.Size() > 0)
	{
		Monkey monkey = queue.Front();
		queue.Pop();
	
		if (monkey._pos.first == w - 1 && monkey._pos.second == h - 1)
		{
			cout << monkey.moveCnt - 1;
			return 0;
		}

		// 원숭이 움직임
		MoveWay(&queue, monkey, monkeyPoints, monkeyWayCnt, w, h, false);

		// 말 움직임 --> k보다 작을 때만 진행
		if (monkey.horseCnt > 0)
		{
			MoveWay(&queue, monkey, horsePoints, horseWayCnt, w, h, true);
		}
	}

	cout << -1;

	return 0;
}