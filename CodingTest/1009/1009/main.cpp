#include <iostream>
#include <list>
using namespace std;

class CircularQueue
{
public:
	void Push(int item)
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

	int MoveTo(int count)
	{
		list<int>::iterator i = _list.begin();

		int index = 1;
		while (count > index)
		{
			index++;
			if (i == _list.end()) i = _list.begin();
			else i++;
		}

		return *i;
	}

	bool Contain(int item)
	{
		for (list<int>::iterator i = _list.begin(); i != _list.end(); i++)
		{
			if (item == *i) return true;
		}

		return false;
	}

private:
	list<int> _list;
};

// 자릿수로 푸는 문제
// long long int로 a, b, sum의 범위를 정해줘야 맞는 값이 나옴 --> sum *= a; 연산이 필요해서 아니면 범위를 넘어감

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	list<int> storage;

	for (int i = 0; i < n; i++)
	{
		long long int a, b;
		cin >> a >> b;

		CircularQueue queue;
		long long int sum = a;
		while (queue.Contain(sum % 10) == false)
		{
			queue.Push(sum % 10);
			sum *= a;
		}

		int size = queue.Size();

		int index = b % size;
		if (index == 0) index = size;
		storage.push_back(queue.MoveTo(index));
	}

	for (list<int>::iterator i = storage.begin(); i != storage.end(); i++)
	{
		list<int>::iterator tmp = i;

		int item;
		if (*i == 0) item = 10;
		else item = *i;

		if(++tmp == storage.end()) cout << item;
		else cout << item << '\n';
	}

	return 0;
}