#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Node
{
public:
	vector<int> _closeNodeIndexes;
	bool _visit = false;
	int icon = 0;
	int depth = 0;
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

	Node* Front()
	{
		return _list.front();
	}

	Node* Back()
	{
		return _list.back();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	list<Node*> _list;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	Node* nodes = new Node[n];
	for (int i = 0; i < n; i++)
	{
		nodes[i].icon = i + 1;
	}

	int start, end;
	cin >> start >> end;

	int link;
	cin >> link;
	for (int i = 0; i < link; i++)
	{
		int a, b;
		cin >> a >> b;

		nodes[a - 1]._closeNodeIndexes.push_back(b - 1);
		nodes[b - 1]._closeNodeIndexes.push_back(a - 1);
	}

	int cnt;

	Queue queue;
	
	nodes[start - 1]._visit = true;
	queue.Push(&nodes[start - 1]);

	while (queue.IsEmpty() == false)
	{
		Node* node = queue.Front();
		queue.Pop();

		int depth = node->depth;
		if (node->icon == end)
		{
			cout << depth;
			return 0;
		}

		depth++; // 여기서 depth 증가

		int size = node->_closeNodeIndexes.size();
		for (int i = 0; i < size; i++)
		{
			int index = node->_closeNodeIndexes[i];
			if (nodes[index]._visit == true) continue;
			
			nodes[index].depth = depth; // depth 키워주기
			nodes[index]._visit = true;
			queue.Push(&nodes[index]);
		}
	}

	cout << -1;

	return 0;
}