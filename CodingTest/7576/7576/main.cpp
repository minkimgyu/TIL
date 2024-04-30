#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int maxSize = 1000;
int map[maxSize][maxSize];

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

vector<pair<int, int>> ReturnCloseNodes(pair<int, int> pos, int m, int n)
{
	vector<pair<int, int>> closeNodes;

	pair<int, int> leftNode;
	leftNode.first = pos.first - 1;
	leftNode.second = pos.second;
	if(leftNode.first >= 0) closeNodes.push_back(leftNode);

	pair<int, int> rightNode;
	rightNode.first = pos.first + 1;
	rightNode.second = pos.second;
	if (rightNode.first < m) closeNodes.push_back(rightNode);

	pair<int, int> upNode;
	upNode.first = pos.first;
	upNode.second = pos.second - 1;
	if (upNode.second >= 0) closeNodes.push_back(upNode);

	pair<int, int> downNode;
	downNode.first = pos.first;
	downNode.second = pos.second + 1;
	if (downNode.second < n) closeNodes.push_back(downNode);
	
	return closeNodes;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	int mapSize = 0;

	Queue<pair<int, int>> queue;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			map[i][j] = tmp;

			if (tmp != -1) mapSize++;

			if (tmp == -1 || tmp == 0) continue;

			pair<int, int> pos;
			pos.first = j;
			pos.second = i;
			queue.Push(pos);
		}
	}
	
	int time = 0;
	int afterCnt = 0;

	while (mapSize > afterCnt)
	{
		time++;
		int pushCnt = 0;

		int queueSize = queue.Size();
		if (queueSize == 0)
		{
			cout << -1;
			return 0;
		}

		for (int k = 0; k < queueSize; k++)
		{
			pair<int, int> frontItem = queue.Front();
			queue.Pop();

			vector<pair<int, int>> closeNodes = ReturnCloseNodes(frontItem, m, n);
			int closeNodeSize = closeNodes.size();
			for (int k = 0; k < closeNodeSize; k++)
			{
				int closePosValue = map[closeNodes[k].second][closeNodes[k].first];
				if (closePosValue != 0) continue;

				map[closeNodes[k].second][closeNodes[k].first] = map[frontItem.second][frontItem.first] + 1;
				queue.Push(closeNodes[k]);
			}
		}

		afterCnt += queueSize;
	}

	cout << time - 1;
	return 0;
}