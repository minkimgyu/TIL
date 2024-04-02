#include <iostream>
#include <list>
using namespace std;

class Deque
{
public:
	void PushBack(char item)
	{
		_list.push_back(item);
	}

	void PushFront(char item)
	{
		_list.push_front(item);
	}

	char Front()
	{
		return _list.front();
	}

	char Back()
	{
		return _list.back();
	}

	void PopBack()
	{
		_list.pop_back();
	}

	void PopFront()
	{
		_list.pop_front();
	}

	int Size()
	{
		return _list.size();
	}

	bool IsEmpty()
	{
		int size = Size();
		return size == 0;
	}

	void Print()
	{
		for (list<char>::iterator i = --_list.end(); i != _list.begin(); i--)
		{
			cout << *i;
		}

		cout << *_list.begin();
	}

private:
	list<char> _list;
	list<char>::iterator _iter;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Deque deque;

	const int size = 51;
	char* arr = new char[size];

	cin.getline(arr, size);

	int index = 0;
	char start;
	while (1)
	{
		if (arr[index] == '\0') break;

		if (index == 0) 
		{
			start = arr[0];
			deque.PushBack(start);
			index++;
			continue;
		}

		if (start <= arr[index])
		{
			deque.PushFront(arr[index]);
		}
		else
		{
			deque.PushBack(arr[index]);
		}

		start = arr[index];
		index++;
	}

	deque.Print();

	return 0;
}