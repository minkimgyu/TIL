#include <iostream>
#include <list>
#include <vector>
using namespace std;

const int moveCnt = 8;
pair<int, int> movePos[moveCnt] 
= { {2, 1},  {-2, 1}, {2, -1}, {-2, -1},
	{1, 2}, {1, -2}, {-1, -2}, {-1, 2} };

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

vector<pair<int, int>> ReturnMovePoints(pair<int, int> pos, int n)
{
	vector<pair<int, int>> points;

	for (int i = 0; i < moveCnt; i++)
	{
		int xPos = pos.first + movePos[i].first;
		int yPos = pos.second + movePos[i].second;

		if (xPos < 0 || xPos >= n || yPos < 0 || yPos >= n) continue;
		points.push_back({ xPos, yPos });
	}

	return points;
}

// BFS 알고리즘을 이용한 기본적인 문제
// 1씩 더해주면서 진행해준다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;

	vector<int> results;

	for (int i = 0; i < cnt; i++)
	{
		int chessSize;
		cin >> chessSize;

		int** map = new int* [chessSize];
		for (int i = 0; i < chessSize; i++)
		{
			map[i] = new int[chessSize] {0};
		}

		pair<int, int> start, end;

		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		Queue<pair<int, int>> queue;
		queue.Push(start);

		while (queue.IsEmpty() == false)
		{
			pair<int, int> pos = queue.Front();
			queue.Pop();

			int value = map[pos.second][pos.first];
			if (pos.second == end.second && pos.first == end.first)
			{
				results.push_back(map[end.second][end.first]);
				break;
			}

			vector<pair<int, int>> points = ReturnMovePoints(pos, chessSize);
			int pointSize = points.size();

			for (int i = 0; i < pointSize; i++)
			{
				if (map[points[i].second][points[i].first] > 0) continue;

				map[points[i].second][points[i].first] += value + 1;
				queue.Push(points[i]);
			}
		}
	}

	int resultSize = results.size();
	for (int i = 0; i < resultSize; i++)
	{
		cout << results[i];
		if(i != resultSize - 1) cout << '\n';
	}

	return 0;
}