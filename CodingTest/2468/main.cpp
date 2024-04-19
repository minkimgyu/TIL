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

	T Front()
	{
		return _list.front();
	}

	T Back()
	{
		return _list.back();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Size()
	{
		return _list.size();
	}

private:
	list<T> _list;
};

struct Node;

const int mapSize = 100;
Node* map[mapSize][mapSize];

struct Node
{
public:
	Node(int icon, int yIndex, int xIndex)
	{
		_height = icon;
		_yIndex = yIndex;
		_xIndex = xIndex;
	}

	vector<Node*> ReturnCloseNodes(int size)
	{
		vector<Node*> closeNodes;

		if (_xIndex > 0)
		{
			Node* leftNode = map[_yIndex][_xIndex - 1];
			closeNodes.push_back(leftNode);
		}

		if (_xIndex < size - 1)
		{
			Node* rightNode = map[_yIndex][_xIndex + 1];
			closeNodes.push_back(rightNode);
		}

		if (_yIndex > 0)
		{
			Node* upNode = map[_yIndex - 1][_xIndex];
			closeNodes.push_back(upNode);
		}

		if (_yIndex < size - 1)
		{
			Node* downNode = map[_yIndex + 1][_xIndex];
			closeNodes.push_back(downNode);
		}

		return closeNodes;
	}

public:
	int _height;
	int _xIndex, _yIndex;
	bool _visit = false;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int mapTop = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;

			if (tmp > mapTop) mapTop = tmp;
			map[i][j] = new Node(tmp, i, j);
		}
	}

	int waterHeight = 0;
	int maxLandCnt = 0;

	while (mapTop > waterHeight)
	{
		int landCnt = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j]->_height <= waterHeight) continue;
				if (map[i][j]->_visit == true) continue;

				Queue<Node*> queue;

				map[i][j]->_visit = true;
				queue.Push(map[i][j]);

				landCnt++;

				while (queue.IsEmpty() == false)
				{
					Node* node = queue.Front();
					queue.Pop();

					vector<Node*> nodes = node->ReturnCloseNodes(n);
					int size = nodes.size();
					for (int k = 0; k < size; k++)
					{
						if (nodes[k]->_height <= waterHeight) continue;
						if (nodes[k]->_visit == true) continue;

						nodes[k]->_visit = true;
						queue.Push(nodes[k]);
					}
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j]->_visit = false;
			}
		}

		if (landCnt > maxLandCnt) maxLandCnt = landCnt;
		waterHeight++;
	}

	cout << maxLandCnt;

	return 0;
}