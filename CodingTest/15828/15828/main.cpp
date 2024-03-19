#include <iostream>
#include <list>
using namespace std;

class Router
{
public:
	Router(int maxSize)
	{
		_maxSize = maxSize;
	}

public:
	void Push(int item)
	{
		int currentSize = Size();
		if (currentSize >= _maxSize) return;

		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Top()
	{
		return _list.front();
	}

	int Size()
	{
		return _list.size();
	}

private:
	list<int> _list;
	int _maxSize;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxSize;
	cin >> maxSize;

	// 큐의 기본만 이해하면 풀 수 있는 문제

	Router* router = new Router(maxSize);

	while (1)
	{
		int tmp;
		cin >> tmp;

		if (tmp == -1) break;

		else if(tmp == 0) router->Pop();
		else router->Push(tmp);
	}

	int size = router->Size();

	if (size == 0)
	{
		cout << "empty";
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		if(i == size - 1) cout << router->Top();
		else cout << router->Top() << " ";

		router->Pop();
	}

	delete router;

	return 0;
}