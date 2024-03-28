#include <iostream>
using namespace std;

class Node
{
public:
	Node(char value) : _value(value), _left(nullptr), _right(nullptr) {}

public:
	char _value;
	Node* _left;
	Node* _right;
};

class Tree
{
public:
	void PreorderTraverse(Node* node) // 전위 순회
	{
		cout << node->_value;
		if (node->_left != nullptr) PreorderTraverse(node->_left);
		if (node->_right != nullptr) PreorderTraverse(node->_right);
	}

	void InorderTraversal(Node* node) // 중위 순회
	{
		if (node->_left != nullptr) InorderTraversal(node->_left);
		cout << node->_value;
		if (node->_right != nullptr) InorderTraversal(node->_right);
	}

	void PostorderTraverse(Node* node) // 후위 순회
	{
		if (node->_left != nullptr) PostorderTraverse(node->_left);
		if (node->_right != nullptr) PostorderTraverse(node->_right);
		cout << node->_value;
	}

	void AddNode(Node* node, char findValue, char leftValue, char rightValue)
	{
		if (node->_value == findValue)
		{
			if (leftValue != '.') node->_left = new Node(leftValue);
			if (rightValue != '.') node->_right = new Node(rightValue);
		}

		if (node->_left != nullptr) AddNode(node->_left, findValue, leftValue, rightValue);
		if (node->_right != nullptr) AddNode(node->_right, findValue, leftValue, rightValue);
	}

public:
	Node* _rootNode;
};

// 트리의 순회를 이용하는 문제
// 전위, 중위, 후위에 대해서 잘 이해해두기
// AddNode 과정이 좀 복잡했다.
// return이 아닌 value를 지정하는 방법으로 해보자

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Tree tree;
	tree._rootNode = new Node('A');

	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;

		tree.AddNode(tree._rootNode, a, b, c);
	}

	tree.PreorderTraverse(tree._rootNode);
	cout << '\n';
	tree.InorderTraversal(tree._rootNode);
	cout << '\n';
	tree.PostorderTraverse(tree._rootNode);

	return 0;
}