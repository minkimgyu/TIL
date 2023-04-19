#include <iostream>
#include <list>
#include <string>
using namespace std;

class Queue
{
	list<int> li;

public:
	void Push(int num)
	{
		li.emplace_back(num);
	}

	int Pop()
	{
		if (li.size() <= 0) return -1;

		int tmp = li.front();
		li.pop_front();

		return tmp;
	}

	int Size() { return li.size(); }

	bool Empty()
	{
		if (li.size() == 0)
			return true;
		else
			return false;
	}

	int Front()
	{
		if (li.size() != 0)
		{
			int tmp = li.front();
			return tmp;
		}
		else
		{
			return -1;
		}
	}

	int Back()
	{
		if (li.size() != 0)
		{
			int tmp = li.back();
			return tmp;
		}
		else
		{
			return -1;
		}
	}
};

void SolveWord(Queue* qu, string st);

int main()
{
	Queue qu;
	int count;

	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++)
	{
		string st;
		getline(cin, st);
		SolveWord(&qu, st);
	}

	return 0;
}

void SolveWord(Queue* qu, string st)
{
	if (st.find("push") != string::npos)
	{
		int tmp = stoi(st.substr(5, st.size() - 5));
		qu->Push(tmp);
	}
	else if (st.find("pop") != string::npos)
	{
		cout << qu->Pop() << '\n';
	}
	else if (st.find("front") != string::npos)
	{
		cout << qu->Front() << '\n';
	}
	else if (st.find("back") != string::npos)
	{
		cout << qu->Back() << '\n';
	}
	else if (st.find("size") != string::npos)
	{
		cout << qu->Size() << '\n';
	}
	else if (st.find("empty") != string::npos)
	{
		cout << qu->Empty() << '\n';
	}
}