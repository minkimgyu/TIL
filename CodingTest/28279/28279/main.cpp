#include <iostream>
#include <list>

#include<string>
#include<vector>
#include<sstream>

using namespace std;

class Deque
{
private:
	std::list<int> list;

public:
	void PushFront(int item)
	{
		list.push_front(item);
	}

	void PushBack(int item)
	{
		list.push_back(item);
	}

	bool isClear()
	{
		return list.size() == 0;
	}

	int Size()
	{
		return list.size();
	}

	int Front()
	{
		return list.front();
	}

	int Back()
	{
		return list.back();
	}

	void PopFront()
	{
		list.pop_front();
	}

	void PopBack()
	{
		list.pop_back();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	Deque deque;
	const int size = 10;


	for (int i = 0; i < n; i++)
	{
		char order[size];
		cin.getline(order, size);

		istringstream ss(order);
		string stringBuffer;
		vector<int> convertedOrder;

		while (getline(ss, stringBuffer, ' ')) {

			int tmp = stoi(stringBuffer);
			convertedOrder.push_back(tmp);
		}

		if (convertedOrder[0] == 1)
		{
			deque.PushFront(convertedOrder[1]);
		}
		else if (convertedOrder[0] == 2)
		{
			deque.PushBack(convertedOrder[1]);
		}
		else if (convertedOrder[0] == 3)
		{
			bool isClear = deque.isClear();
			if (isClear == true) cout << -1 << '\n';
			else
			{
				int front = deque.Front();
				deque.PopFront();
				cout << front << '\n';
			}
		}
		else if (convertedOrder[0] == 4)
		{
			bool isClear = deque.isClear();
			if (isClear == true) cout << -1 << '\n';
			else
			{
				int front = deque.Back();
				deque.PopBack();
				cout << front << '\n';
			}
		}
		else if (convertedOrder[0] == 5)
		{
			cout << deque.Size() << '\n';
		}
		else if (convertedOrder[0] == 6)
		{
			bool isClear = deque.isClear();
			if (isClear) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (convertedOrder[0] == 7)
		{
			bool isClear = deque.isClear();
			if (isClear == true) cout << -1 << '\n';
			else
			{
				int front = deque.Front();
				cout << front << '\n';
			}
		}
		else if (convertedOrder[0] == 8)
		{
			bool isClear = deque.isClear();
			if (isClear == true) cout << -1 << '\n';
			else
			{
				int front = deque.Back();
				cout << front << '\n';
			}
		}
	}

	return 0;
}