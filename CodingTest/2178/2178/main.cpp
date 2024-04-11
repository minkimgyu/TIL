#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Node
{
public:
	Node(bool canPass, int nIndex, int mIndex) 
		: _canPass(canPass), _nIndex(nIndex), _mIndex(mIndex) {}

	//int GetF() { return G + H; }

public:
	bool _canPass = false;

	bool _alreadyPass = false;

	int _nIndex = 0;
	int _mIndex = 0;

	int _passCnt = 0;

	//float G, H = 0;
	// g는 시작 노드와의 거리 --> 계속 업데이트 필요함
	// h는 목표까지의 거리
};

Node* arr[100][100];

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

vector<Node*> FindCloseNode(Node* node, int maxN, int maxM)
{
	vector<Node*> _vec;

	int passCnt = ++node->_passCnt;

	if (node->_mIndex - 1 >= 0)
	{
		Node* leftNode = arr[node->_nIndex][node->_mIndex - 1];

		if (leftNode->_alreadyPass == false && leftNode->_canPass == true)
		{
			leftNode->_passCnt = passCnt;
			leftNode->_alreadyPass = true;
			_vec.push_back(leftNode);
		}
	}
	
	if (node->_mIndex + 1 < maxM)
	{
		Node* rightNode = arr[node->_nIndex][node->_mIndex + 1];

		if (rightNode->_alreadyPass == false && rightNode->_canPass == true)
		{
			rightNode->_passCnt = passCnt;
			rightNode->_alreadyPass = true;
			_vec.push_back(rightNode);
		}
	}

	if (node->_nIndex - 1 >= 0)
	{
		Node* upNode = arr[node->_nIndex - 1][node->_mIndex];

		if (upNode->_alreadyPass == false && upNode->_canPass == true)
		{
			upNode->_passCnt = passCnt;
			upNode->_alreadyPass = true;
			_vec.push_back(upNode);
		}
	}

	if (node->_nIndex + 1 < maxN)
	{
		Node* downNode = arr[node->_nIndex + 1][node->_mIndex];

		if (downNode->_alreadyPass == false && downNode->_canPass == true)
		{
			downNode->_passCnt = passCnt;
			downNode->_alreadyPass = true;
			_vec.push_back(downNode);
		}
	}

	return _vec;
}


// 방문하지 않은 노드만 Queue에 넣는 방식으로 진행한다.
// 주변 노드를 찾을 때 _alreadyPass를 true로 만들어주면서 중복되서 Queue에 들어가지 못하게 해야한다.
// 그외의 접근법으로는 BFS를 사용하면 A*와 유사한 방식으로 탐색이 가능하다 --> 최단 경로 구하기
// DFS는 최단 횟수를 구할 때 사용된다고 한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		int maxReadCnt = m + 1;
		char* tmp = new char[maxReadCnt];
		cin.getline(tmp, maxReadCnt);

		for (int j = 0; j < maxReadCnt; j++)
		{
			bool canPass = false;

			if (tmp[j] == '0') canPass = false; // 마지막
			else if (tmp[j] == '1') canPass = true;
			else continue; // \0 인 경우

			arr[i][j] = new Node(canPass, i, j);
		}
	}
	
	arr[0][0]->_passCnt = 1;

	Queue<Node*> queue;
	queue.Push(arr[0][0]);

	while (queue.Size() > 0)
	{
		Node* node = queue.Front();
		queue.Pop();

		// 도착한 경우
		if (node->_nIndex == n - 1 && node->_mIndex == m - 1)
		{
			cout << node->_passCnt;
			break;
		}

		vector<Node*> closeNodes = FindCloseNode(node, n, m);
		int size = closeNodes.size();
		for (int i = 0; i < size; i++)
		{
			queue.Push(closeNodes[i]);
		}
	}

	return 0;
}