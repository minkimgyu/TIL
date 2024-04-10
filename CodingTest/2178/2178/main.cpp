#include <iostream>
#include <list>
using namespace std;

int arr[100][100];

class Node
{
public:
	int _passCnt;
	int _index;
	Node* _parentNode;
};

template <typename T>
class Queue
{
public:
	void Push(int item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_back();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Front()
	{
		return _list.front();
	}

	int Back()
	{
		return _list.back();
	}

private:
	list<int> _list;
};

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
		char* tmp = new char[m + 1];
		cin.getline(tmp, m);
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = (int)tmp[j] - (int)'0';
		}
	}
	
	Queue<> queue;



	return 0;
}