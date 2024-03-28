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
	void PreorderTraverse(Node* node) // ���� ��ȸ
	{
		cout << node->_value;
		if (node->_left != nullptr) PreorderTraverse(node->_left);
		if (node->_right != nullptr) PreorderTraverse(node->_right);
	}

	void InorderTraversal(Node* node) // ���� ��ȸ
	{
		if (node->_left != nullptr) InorderTraversal(node->_left);
		cout << node->_value;
		if (node->_right != nullptr) InorderTraversal(node->_right);
	}

	void PostorderTraverse(Node* node) // ���� ��ȸ
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

// Ʈ���� ��ȸ�� �̿��ϴ� ����
// ����, ����, ������ ���ؼ� �� �����صα�
// AddNode ������ �� �����ߴ�.
// return�� �ƴ� value�� �����ϴ� ������� �غ���

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