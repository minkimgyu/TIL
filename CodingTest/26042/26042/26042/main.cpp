#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue
{
public:
	void Push(T item)
	{
		_list.push_back(item);
	}

	void Pop()
	{
		_list.pop_front();
	}

	int Front()
	{
		return _list.front();
	}

	int Back()
	{
		return _list.back();
	}

	bool IsEmpty()
	{
		int size = Size();
		return size == 0;
	}

	int Size()
	{
		return _list.size();
	}

private:
	list<int> _list;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Queue<int> queue;

	int n;
	cin >> n;
	cin.ignore();

	int storedSize = -1;
	int storedBack = -1;

	for (int i = 0; i < n; i++)
	{
		const int size = 15;
		char arr[size];
		cin.getline(arr, size);

		if (arr[0] == '1')
		{
			int index = 2;
			while (1)
			{
				if (arr[index] == '\0') break;
				index++;
			}

			char* tmp = new char[index - 2] { 0 };

			index = 2;
			while (1)
			{
				if (arr[index] == '\0')
				{
					tmp[index - 2] = '\0';
					break;
				}

				tmp[index - 2] = arr[index];
				index++;
			}

			int value = atoi(tmp);
			queue.Push(value);
		}
		else if (arr[0] == '2')
		{
			queue.Pop();
			continue;
		}

		int queueSize = queue.Size();
		int back = queue.Back();

		if (storedSize < queueSize)
		{
			storedSize = queueSize;
			storedBack = back;
		}
		else if (queueSize > 0 && storedSize == queueSize && back < storedBack)
		{
			storedBack = back;
		}
	}

	cout << storedSize << " " << storedBack;

	return 0;
}