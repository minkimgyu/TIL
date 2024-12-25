#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Node
{
public:
	void AddNodeIndex(int index)
	{
		_closeNodeIndex.push_back(index);
	}

public:
	int _index = 0;
	bool _visit = false;

	vector<int> _closeNodeIndex;
};

class Queue
{
public:
	void Push(Node* item)
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	Node* arr = new Node[n];
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		start--;
		end--;

		arr[start].AddNodeIndex(end);
		arr[start]._index = start + 1;

		arr[end].AddNodeIndex(start);
		arr[end]._index = end + 1;

	}

	Queue queue;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i]._visit == true) continue;

		cnt++;
		queue.Push(&arr[i]);
		arr[i]._visit = true;

		while (queue.Size() > 0)
		{
			Node* front = queue.Front();
			queue.Pop();

			int size = front->_closeNodeIndex.size();
			for (int i = 0; i < size; i++)
			{
				int index = front->_closeNodeIndex[i];
				if (arr[index]._visit == true) continue;

				arr[index]._visit = true;
				queue.Push(&arr[index]);
			}
		}
	}
	
	cout << cnt;

	return 0;
}