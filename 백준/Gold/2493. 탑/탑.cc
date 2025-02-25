#include <iostream>
#include <vector>
using namespace std;

struct Data
{
public:
	int index, value;
};

template <typename T>
class Stack
{
public:
	void Push(T item)
	{
		_vec.push_back(item);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Size()
	{
		return _vec.size();
	}

	T Top()
	{
		int size = Size();
		return _vec[size - 1];
	}

private:
	vector<T> _vec;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<Data> stack;

	int cnt;
	cin >> cnt;

	for (int i = 1; i <= cnt; i++)
	{
		int tmp;
		cin >> tmp;

		Data data;
		data.index = i;
		data.value = tmp;

		int output = -1;

		if (i == 1)
		{
			output = 0;
		}
		else
		{
			while (stack.IsEmpty() == false)
			{
				if (stack.Top().value < tmp) stack.Pop();
				else break;
			}

			if(stack.IsEmpty()) output = 0;
			else output = stack.Top().index;
		}

		stack.Push(data);

		if (i == cnt) cout << output;
		else cout << output << " ";
	}

	return 0;
}