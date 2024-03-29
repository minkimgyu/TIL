#include <iostream>
#include <list>
using namespace std;

class Deque
{
public:
	char Front()
	{
		return _list.front();
	}

	char Back()
	{
		return _list.back();
	}

	void PushFront(char item)
	{
		_list.push_front(item);
	}

	void PushBack(char item)
	{
		_list.push_back(item);
	}

	void PopFront()
	{
		_list.pop_front();
	}

	void PopBack()
	{
		_list.pop_back();
	}

	void Print()
	{
		for (list<char>::iterator iter = _list.begin(); iter != _list.end(); iter++)
		{
			cout << *iter;
		}
	}

private:
	list<char> _list;
};

int main()
{
	int n;
	cin >> n;

	list<Deque> storedList;

	for (int i = 0; i < n; i++)
	{
		int arrLength;
		cin >> arrLength;

		list<char> list;
		for (int i = 0; i < arrLength; i++)
		{
			char tmp;
			cin >> tmp;
			list.push_back(tmp);
		}

		Deque deque;
		char center;
		for (int i = 0; i < arrLength; i++)
		{
			char item = list.front();
			list.pop_front();

			if (i == 0)
			{
				center = item;
				deque.PushBack(item);
			}
			else
			{
				if ((int)item <= (int)center && 
					(int)item <= (int)deque.Front()) // 반례 검출 주의 --> 무조건 앞에는 아스키 코드가 같거나 작은 값이 나와야함
				{
					deque.PushFront(item);
				}
				else
				{
					deque.PushBack(item);
				}
			}
		}

		storedList.push_back(deque);
	}

	for (list<Deque>::iterator i = storedList.begin(); i != storedList.end(); i++)
	{
		i->Print();
		if(i != --storedList.end()) cout << '\n';
	}

	return 0;
}