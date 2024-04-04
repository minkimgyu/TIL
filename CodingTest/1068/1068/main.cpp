#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
public:
	void Push(T item)
	{
		_vec.push_back(item);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	T Top()
	{
		int size = Size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	vector<T> _vec;
};

class Node
{
public:
	int _item = 0;
	int _parentIndex = 0;

private:
	vector<Node*> _childNodes;

public:
	void SetChild(Node* node)
	{
		_childNodes.push_back(node);
	}

	vector<Node*> GetChildren()
	{
		return _childNodes;
	}

	bool IsLeafNode()
	{
		int size = _childNodes.size();
		return size == 0;
	}

	void AddNode(Node* node)
	{
		_childNodes.push_back(node);
	}
};

class Tree
{
public:
	void SetRootNode(Node* rootNode)
	{
		_rootNode = rootNode;
	}

	void DFS(int ignoreItem, int* cnt)
	{
		if (_rootNode->_item == ignoreItem) // 루트 노드를 무시할 경우
		{
			*cnt = 0;
			return;
		}

		Stack<Node*> _stack;
		_stack.Push(_rootNode);

		while (_stack.Size() > 0)
		{
			Node* node = _stack.Top();
			_stack.Pop();

			if (node->_item == ignoreItem) continue;

			bool isLeafNode = node->IsLeafNode();
			if (isLeafNode == false)
			{
				vector<Node*> tmpNodes = node->GetChildren();
				int size = tmpNodes.size();

				int pushCnt = 0;
				for (int i = 0; i < size; i++)
				{
					if (tmpNodes[i]->_item == ignoreItem) continue;
					_stack.Push(tmpNodes[i]);
					pushCnt++;
				}

				if (pushCnt == 0) *cnt += 1; // 모든 자식이 무시되는 경우
			}
			else
			{
				*cnt += 1; // 리프 노드인 경우
			}
		}
	}

private:
	Node* _rootNode = nullptr;
	vector<Node*> _storedNodes;
};

// DFS를 사용해서 배회하는 문제
// 반례가 매우매우 많다.

// 1. 입력 순서가 일정하지 않을 수 있다. --> 루트 노드부터 입력되지 않을 가능성이 있다.
// 2. 루트 노드가 제외될 수 있다. --> 이 경우는 0을 반환한다.
// 3. 루트 노드가 단말 노드가 될 수 있다. --> Stack에 넣는 값이 없는 경우를 따로 판정한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Tree tree;

	int n;
	cin >> n;

	Node* nodes = new Node[n];

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		nodes[i]._item = i;
		nodes[i]._parentIndex = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		if (nodes[i]._parentIndex == -1)
		{
			tree.SetRootNode(&nodes[i]); // 루트 노드로 지정
		}
		else
		{
			int parentIndex = nodes[i]._parentIndex;
			nodes[parentIndex].SetChild(&nodes[i]);
		}
	}

	int cnt = 0;
	int ignoreItem;
	cin >> ignoreItem;

	tree.DFS(ignoreItem, &cnt);

	cout << cnt;

	delete[] nodes;

	return 0;
}