#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Link
{
public:
	int _start, _end;
};

class Node
{
public:
	void AddNodeIndex(int index)
	{
		_closeNodeIndexes.push_back(index);
	}

public:
	int _num;
	vector<int> _closeNodeIndexes;
	bool _visit;
};

class Stack
{
public:
	void Push(Node* node)
	{
		_vec.push_back(node);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	Node* Top()
	{
		return _vec.back();
	}

private:
	vector<Node*> _vec;
};


class Queue
{
public:
	void Push(Node* node)
	{
		_list.push_back(node);
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

	Node* Front()
	{
		return _list.front();
	}

	Node* Back()
	{
		return _list.back();
	}

private:
	list<Node*> _list;
};

bool compare(int a, int b)
{
	return a < b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	Node* nodes = new Node[n];
	Link* links = new Link[m];
	for (int i = 0; i < m; i++)
	{
		cin >> links[i]._start >> links[i]._end;
	}

	for (int i = 0; i < n; i++)
	{
		nodes[i]._num = i + 1;
		nodes[i]._visit = false;
	}

	for (int i = 0; i < m; i++)
	{
		int start = links[i]._start - 1;
		int end = links[i]._end - 1;

		nodes[start].AddNodeIndex(end);
		nodes[end].AddNodeIndex(start);
	}

	for (int i = 0; i < n; i++)
	{
		sort(
			nodes[i]._closeNodeIndexes.begin(),
			nodes[i]._closeNodeIndexes.end(), 
			compare);
	}

	Stack stack;
	stack.Push(&nodes[v - 1]);

	vector<int> dfsList;
	while (stack.Size() > 0)
	{
		Node* node = stack.Top();
		stack.Pop();
		if (node->_visit == true) continue;
		node->_visit = true;

		dfsList.push_back(node->_num);

		int size = node->_closeNodeIndexes.size();
		for (int i = size - 1; i >= 0; i--)
		{
			int index = node->_closeNodeIndexes[i];
			if (nodes[index]._visit == true) continue;

			stack.Push(&nodes[index]);
		}
	}

	int dfsListSize = dfsList.size();
	for (int i = 0; i < dfsListSize; i++)
	{
		if (i == dfsListSize - 1) cout << dfsList[i];
		else cout << dfsList[i] << " ";
	}

	for (int i = 0; i < n; i++) nodes[i]._visit = false;
	cout << "\n";

	Queue queue;

	nodes[v - 1]._visit = true;
	queue.Push(&nodes[v - 1]);

	vector<int> bfsList;
	while (queue.Size() > 0)
	{
		Node* node = queue.Front();
		queue.Pop();

		bfsList.push_back(node->_num);

		int size = node->_closeNodeIndexes.size();
		for (int i = 0; i < size; i++)
		{
			int index = node->_closeNodeIndexes[i];
			if (nodes[index]._visit == true) continue;

			nodes[index]._visit = true;
			queue.Push(&nodes[index]);
		}
	}

	int bfsListSize = bfsList.size();
	for (int i = 0; i < bfsListSize; i++)
	{
		if (i == bfsListSize - 1) cout << bfsList[i];
		else cout << bfsList[i] << " ";
	}

	return 0;
}