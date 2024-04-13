#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;

class Node;

const int length = 25;

Node* arr[length][length];

class Node
{

public:
	Node(int index, int x, int y) : _index(index), _x(x), _y(y) {}

	vector<Node*> ReturnCloseNode(int n)
	{
		vector<Node*> tmpVec;

		if (_x - 1 > -1 && arr[_y][_x - 1]->_alreadyPass == false
			&& arr[_y][_x - 1]->_index != 0)
		{
			Node* leftNode = arr[_y][_x - 1];
			tmpVec.push_back(leftNode);
		}

		if (n - 1 > _x && arr[_y][_x + 1]->_alreadyPass == false
			&& arr[_y][_x + 1]->_index != 0)
		{
			Node* rightNode = arr[_y][_x + 1];
			tmpVec.push_back(rightNode);
		}

		if (_y - 1 > -1 && arr[_y - 1][_x]-> _alreadyPass == false
			&& arr[_y - 1][_x]->_index != 0)
		{
			Node* upNode = arr[_y - 1][_x];
			tmpVec.push_back(upNode);
		}

		if (n - 1 > _y && arr[_y + 1][_x]->_alreadyPass == false
			&& arr[_y + 1][_x]->_index != 0)
		{
			Node* downNode = arr[_y + 1][_x];
			tmpVec.push_back(downNode);
		}

		return tmpVec;
	}

public:
	int _index = 0;
	int _x = 0;
	int _y = 0;
	bool _alreadyPass = false;

};


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

bool compare(int a, int b)
{
	return a < b;
}

// for 루프로 배회하면서 1을 발견하게 된다면
// 주변 노드를 BFS 방식으로 탐색해서 블록의 개수를 찾는다.

// 찾은 후에 방문유무를 체크해준다.

// 시간복잡도가 걱정이었지만 생각보다 탐색을 많이 하지 않는 것 같다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		int size = n + 1;
		char* tmp = new char[size];
		cin.getline(tmp, size);

		for (int j = 0; j < n; j++)
		{
			int index = (int)tmp[j] - (int)'0';
			Node* node = new Node(index, j, i);
			arr[i][j] = node;
		}
	}

	int blockIndex = 0;
	int blockArr[625];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]->_alreadyPass == true
				|| arr[i][j]->_index == 0) continue;

			int cnt = 0;
			Queue<Node*> queue;

			arr[i][j]->_alreadyPass = true;
			queue.Push(arr[i][j]);
			cnt++;

			while (queue.Size() > 0)
			{
				Node* node = queue.Front();
				queue.Pop();

				vector<Node*> nodes = node->ReturnCloseNode(n);
				int size = nodes.size();
				for (int k = 0; k < size; k++)
				{
					nodes[k]->_alreadyPass = true;
					queue.Push(nodes[k]);
					cnt++;
				}
			}

			blockArr[blockIndex] = cnt;
			blockIndex++;
		}
	}

	sort(blockArr, blockArr + blockIndex, compare);

	cout << blockIndex << '\n';
	for (int i = 0; i < blockIndex; i++)
	{
		if (i == blockIndex - 1) cout << blockArr[i];
		else cout << blockArr[i] << '\n';
	}

	return 0;
}