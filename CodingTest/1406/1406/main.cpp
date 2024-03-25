#include <iostream>
#include <vector>
using namespace std;

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

	T Top()
	{
		int size = Size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return _vec.size() == 0;
	}

	void Print()
	{
		int size = Size();
		for (int i = 0; i < size; i++)
		{
			cout << _vec[i];
		}
	}

private:
	vector<T> _vec;
};

// Stack을 사용해서 넣고 빼는 과정이 중요하다!!

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<char> stack;
	Stack<char> tmpStack;

	const int size = 100001;
	char* arr = new char[size];
	cin.getline(arr, size);

	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') break;
		stack.Push(arr[index]);

		index++;
	}

	int cnt;
	cin >> cnt;
	cin.ignore();

	for (int i = 0; i < cnt; i++)
	{
		const int inputCount = 4;
		char* tmp = new char[inputCount];
		cin.getline(tmp, inputCount);

		if (tmp[0] == 'L')
		{
			if (stack.Size() == 0) continue;

			char item = stack.Top();
			tmpStack.Push(item);
			stack.Pop();
		}
		else if (tmp[0] == 'D')
		{
			if (tmpStack.Size() == 0) continue;

			char item = tmpStack.Top();
			stack.Push(item);
			tmpStack.Pop();
		}
		else if (tmp[0] == 'B')
		{
			if (stack.Size() == 0) continue;

			stack.Pop();
		}
		else if (tmp[0] == 'P')
		{
			char item = tmp[2];
			stack.Push(item);
		}
	}

	while (tmpStack.IsEmpty() == false)
	{
		char item = tmpStack.Top();
		stack.Push(item);
		tmpStack.Pop();
	}

	stack.Print();
	return 0;
}