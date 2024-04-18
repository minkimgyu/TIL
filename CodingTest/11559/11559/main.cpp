#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T>
class Queue
{
public:
	void Push(T item)
	{
		return _list.push_back(item);
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

const int rowSize = 6;
const int colSize = 12;

class Node;
Node* map[colSize][rowSize];

class Node
{
public:
	Node(char icon, int yIndex, int xIndex)
	{
		_icon = icon;
		_xIndex = xIndex;
		_yIndex = yIndex;
	}

	vector<Node*> ReturnCloseNodes()
	{
		vector<Node*> closeNodes;

		if (_xIndex > 0)
		{
			Node* leftNode = map[_yIndex][_xIndex - 1];
			closeNodes.push_back(leftNode);
		}

		if (_yIndex > 0)
		{
			Node* upNode = map[_yIndex - 1][_xIndex];
			closeNodes.push_back(upNode);
		}

		if (_xIndex < rowSize - 1)
		{
			Node* rightNode = map[_yIndex][_xIndex + 1];
			closeNodes.push_back(rightNode);
		}

		if (_yIndex < colSize - 1)
		{
			Node* downNode = map[_yIndex + 1][_xIndex];
			closeNodes.push_back(downNode);
		}

		return closeNodes;
	}

public:
	char _icon;
	int _xIndex, _yIndex;
	bool _visited = false;
};

// 어렵네...

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < colSize; i++)
	{
		char* arr = new char[rowSize + 1];
		cin.getline(arr, rowSize + 1);

		for (int j = 0; j < rowSize; j++)
		{
			char icon = arr[j];
			map[i][j] = new Node(icon, i, j);
		}
	}

	int loopCnt = 0;
	bool nowDestroy = false;

	while (1)
	{
		for (int i = colSize - 1; i >= 0; i--)
		{
			for (int j = 0; j < rowSize; j++)
			{
				if (map[i][j]->_icon == '.' || map[i][j]->_visited == true) continue;

				vector<Node*> searchedNode;
				Queue<Node*> queue;

				map[i][j]->_visited = true;
				queue.Push(map[i][j]);

				while (queue.Size() > 0)
				{
					Node* node = queue.Front();
					queue.Pop();

					searchedNode.push_back(node);
					vector<Node*> closeNodes = node->ReturnCloseNodes();
					int closeNodeSize = closeNodes.size();

					for (int i = 0; i < closeNodeSize; i++)
					{
						// 아이콘이 다르거나 이미 방문한 경우는 제외해줘야함
						if (closeNodes[i]->_icon != node->_icon || closeNodes[i]->_visited == true) continue;

						closeNodes[i]->_visited = true;
						queue.Push(closeNodes[i]);
					}
				}

				// 찾을 수 있는 모든 수를 다 찾아야 하기 때문임
				int searchedSize = searchedNode.size();
				if (searchedSize >= 4) nowDestroy = true;

				for (int k = 0; k < searchedSize; k++)
				{
					if (searchedSize >= 4) searchedNode[k]->_icon = '.'; // 해당 노드들을 모두 .으로 바꿔주기

					searchedNode[k]->_visited = false;
				}
			}
		}

		// 내려주기
		for (int j = 0; j < rowSize; j++)
		{
			int bottomPoint = colSize - 1;
			for (int z = bottomPoint; z >= 0; z--)
			{
				if (map[z][j]->_icon == '.') continue; // 뿌요가 있는 경우

				if (bottomPoint == z)
				{
					bottomPoint--; // bottomPoint를 빼줘야한다.
					continue; // stackPoint가 아닌 경우에는 밑으로 내려주기
				}

				// 아이콘 교체해주기
				map[bottomPoint][j]->_icon = map[z][j]->_icon;
				map[z][j]->_icon = '.';
				bottomPoint--;
			}
		}

		if (nowDestroy == false) break; // 터트릴 뿌요가 없는 경우
		else
		{
			nowDestroy = false;
			loopCnt++;
		}
	}

	cout << loopCnt;

	return 0;
}