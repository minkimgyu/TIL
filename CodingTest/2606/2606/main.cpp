#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Node
{
public:
	void AddNode(Node* node)
	{
		_closeNodes.push_back(node);
	}

	vector<Node*> GetNodes()
	{
		return _closeNodes;
	}

public:
	bool _alreadyPushed = false;
	int _index = 0;

private:
	vector<Node*> _closeNodes;
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

// bfs를 활용해서 푸는 문제
// 아쉬웠던 점은 감염된 PC의 개수를 더하는 부분
// 넣을 때마다 개수를 더한다고 생각해보자
// 
// 그래도 반례 추정은 괜찮게 한 듯?
// 사실 더하는 부분만 제대로 맞췄으면 반례 추정도 필요 없었다....

// void Pop()
// {
//	  _list.pop_front();
// }
// 추가로 Queue 구현 시 위 부분 잘 기억해두자 맨날 틀림

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
		nodes[i]._index = i + 1;
	}

	int linkCnt;
	cin >> linkCnt;
	for (int i = 0; i < linkCnt; i++)
	{
		int linkA, linkB;

		cin >> linkA >> linkB;

		Node* a = &nodes[linkA - 1];
		Node* b = &nodes[linkB - 1];
		
		a->AddNode(b);
		b->AddNode(a);
	}

	int infectedCnt = 0;
	Queue<Node*> queue;
	Node* firstNode = &nodes[0];

	firstNode->_alreadyPushed = true; // 넣기 전에 채크해주기
	queue.Push(firstNode);

	while (!queue.IsEmpty())
	{
		Node* node = queue.Front();
		queue.Pop();

		vector<Node*> linkedNodes = node->GetNodes();
		int size = linkedNodes.size();

		for (int i = 0; i < size; i++)
		{
			if (linkedNodes[i]->_alreadyPushed == true) continue;

			queue.Push(linkedNodes[i]);
			infectedCnt++; // 여기서 하나씩 추가
			linkedNodes[i]->_alreadyPushed = true;
		}
	}

	cout << infectedCnt; // 1번 컴퓨터 제외

	return 0;
}