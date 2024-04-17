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

struct Vector2
{
public:
	int _x, _y;
};

class Node;

const int maxSize = 50;
Node* map[maxSize][maxSize];

class Node
{
public:
	vector<Node*> ReturnCloseNodes(int ySize, int xSize)
	{
		vector<Node*> nodes;

		// 'X' 즉 돌이 아닌 경우만 포함한다.
		if (_vector2._x > 0 && map[_vector2._y][_vector2._x - 1]->_icon != 'X') // 왼쪽
		{
			Node* leftNode = map[_vector2._y][_vector2._x - 1];
			nodes.push_back(leftNode);
		}

		if (_vector2._x < xSize - 1 && map[_vector2._y][_vector2._x + 1]->_icon != 'X') // 오른쪽
		{
			Node* rightNode = map[_vector2._y][_vector2._x + 1];
			nodes.push_back(rightNode);
		}

		if (_vector2._y > 0 && map[_vector2._y - 1][_vector2._x]->_icon != 'X') // 위쪽
		{
			Node* upNode = map[_vector2._y - 1][_vector2._x];
			nodes.push_back(upNode);
		}

		if (_vector2._y < ySize - 1 && map[_vector2._y + 1][_vector2._x]->_icon != 'X') // 아래쪽
		{
			Node* downNode = map[_vector2._y + 1][_vector2._x];
			nodes.push_back(downNode);
		}

		return nodes;
	}

public:
	Vector2 _vector2;
	char _icon;
};

// 너무 어렵다...
// 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;
	cin.ignore();

	Node* sPoint = nullptr; // 고슴도치 위치
	vector<Node*> wPoints; // 물이 차있는 위치

	for (int i = 0; i < r; i++)
	{
		char* arr = new char[maxSize + 1]; // 마지막 '\0' 문자 포함
		cin.getline(arr, maxSize + 1);
		for (int j = 0; j < c; j++)
		{
			char obj = arr[j];
			Node* node = new Node();

			node->_vector2._y = i;
			node->_vector2._x = j;
			node->_icon = obj;

			if (obj == 'S') // 고슴도치 위치
			{
				sPoint = node;
			}
			else if (obj == '*') // 물이 차있는 곳
			{
				wPoints.push_back(node);
			}

			map[i][j] = node;
		}
	}

	Queue<Node*> sQ;
	sQ.Push(sPoint);

	vector<Queue<Node*>> wQs;
	int wSize = wPoints.size();
	for (int i = 0; i < wSize; i++)
	{
		Queue<Node*> wQ;
		wQ.Push(wPoints[i]);

		wQs.push_back(wQ);
	}

	int moveCnt = 0;

	while (1)
	{
		for (int i = 0; i < wSize; i++)
		{
			if (wQs[i].IsEmpty() == true) continue; // 비어있는 경우 진행하지 않음

			int popSize = wQs[i].Size(); // 이만큼 돌려줘야함
			for (int j = 0; j < popSize; j++)
			{
				Node* front = wQs[i].Front();
				wQs[i].Pop();

				vector<Node*> closeNodes = front->ReturnCloseNodes(r, c);
				int size = closeNodes.size();
				for (int k = 0; k < size; k++)
				{
					if (closeNodes[k]->_icon == '*' || closeNodes[k]->_icon == 'D') continue; // 이미 물이 차있는 경우나 목적지인 경우 continue 시켜줌

					closeNodes[k]->_icon = '*';
					wQs[i].Push(closeNodes[k]);
				}
			}
		}

		if (sQ.IsEmpty() == true) // 더 이상 진행할 수 없는 경우
		{
			cout << "KAKTUS";
			return 0;
		}

		moveCnt++;

		int popSize = sQ.Size(); // 이만큼 돌려줘야함
		for (int j = 0; j < popSize; j++)
		{
			Node* front = sQ.Front();
			sQ.Pop();

			vector<Node*> closeNodes = front->ReturnCloseNodes(r, c);

			int size = closeNodes.size();
			for (int i = 0; i < size; i++)
			{
				if (closeNodes[i]->_icon == 'S' || closeNodes[i]->_icon == '*') continue; // 이미 지나간 곳이나 물이 있는 경우 continue 시켜줌

				if (closeNodes[i]->_icon == 'D') // 목적지에 도착한 경우
				{
					cout << moveCnt;
					return 0;
				}

				closeNodes[i]->_icon = 'S';
				sQ.Push(closeNodes[i]);
			}
		}
	}

	return 0;
}