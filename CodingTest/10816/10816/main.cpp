#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

//class Node
//{
//public:
//	Node(int item)
//	{
//		_item = item;
//		_count = 1;
//		_left = nullptr;
//		_right = nullptr;
//	}
//
//public:
//	int _item;
//	int _count;
//	Node* _left;
//	Node* _right;
//};
//
//class BinarySearchTree
//{
//private:
//	Node* _root = nullptr;
//
//public:
//	BinarySearchTree()
//	{
//		_root = nullptr;
//	}
//
//private:
//	int SearchCountOfChildNode(int item, Node* node)
//	{
//		int currentNodeItem = node->_item;
//		Node* childnode = nullptr;
//
//		if (item < currentNodeItem)
//		{
//			childnode = node->_left;
//			if (childnode == nullptr) return 0; // �� ã�� ���
//			else
//			{
//				return SearchCountOfChildNode(item, childnode);
//			}
//		}
//		else if (item > currentNodeItem)
//		{
//			childnode = node->_right;
//			if (childnode == nullptr) return 0; // �� ã�� ���
//			else
//			{
//				return SearchCountOfChildNode(item, childnode);
//			}
//		}
//		else
//		{
//			return node->_count; // ã�� ��� --> ���� �������� ���
//		}
//	}
//
//public:
//	void Insert(int item)
//	{
//		if (_root == nullptr)
//		{
//			_root = new Node(item);
//			return;
//		}
//
//		Node* startNode = _root;
//
//		while (true)
//		{
//			int currentNodeItem = startNode->_item;
//			Node* childnode = nullptr;
//
//			if (item < currentNodeItem)
//			{
//				childnode = startNode->_left;
//				if (childnode == nullptr)
//				{
//					startNode->_left = new Node(item);
//					return;
//				}
//				else startNode = childnode;
//			}
//			else if (item > currentNodeItem)
//			{
//				childnode = startNode->_right;
//				if (childnode == nullptr)
//				{
//					startNode->_right = new Node(item);
//					return;
//				}
//				else startNode = childnode;
//			}
//			else // ���� �������� ���
//			{
//				startNode->_count++; // ã�� ���
//				return;
//			}
//		}
//	}
//
//	int SearchCount(int item)
//	{
//		if (_root == nullptr) return 0;
//
//		Node* startNode = _root;
//
//		while (true)
//		{
//			int currentNodeItem = startNode->_item;
//			Node* childnode = nullptr;
//
//			if (item < currentNodeItem)
//			{
//				childnode = startNode->_left;
//				if (childnode == nullptr) return 0;
//				else startNode = childnode;
//			}
//			else if (item > currentNodeItem)
//			{
//				childnode = startNode->_right;
//				if (childnode == nullptr) return 0;
//				else startNode = childnode;
//			}
//			else // ���� �������� ���
//			{
//				return startNode->_count;
//			}
//		}
//	}
//};

// ���� Ž�� Ʈ���� ó���� ������ --> ������ ����� ���� Ʈ���� ��� �ִ� �ð� ���⵵�� O(n)�� �ǹǷ� �ð� �ʰ��� ����.
// ����-�� Ʈ���� map���� �����ؼ� ���� �ذ�
// algorithm ����� ����ؼ� �� ��Ʈ�� sort �Լ��� upper_bound, lower_bound Ǯ�̵� ������
// n + n * log(n) + m * 2n
// m*2n + n + n * log(n)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int> map;

	//BinarySearchTree binarySearchTree;

	int n;
	cin >> n;

	// O(n*log(n) + 2m)

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		if (map.find(tmp) != map.end()) // ã�� ���
		{
			map[tmp] += 1;
		}
		else
		{
			map.insert({ tmp, 1 });
		}

		//binarySearchTree.Insert(tmp);
	}

	int m;
	cin >> m;

	int* arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = map[tmp];
		
		//arr[i] = binarySearchTree.SearchCount(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		if(i == m - 1) cout << arr[i];
		else cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}