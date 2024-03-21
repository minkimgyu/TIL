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

	Stack<char> charStack;

	Stack<int> sumStack;
	Stack<int> tempStack;

	int size = 31;
	char* arr = new char[size];

	cin.getline(arr, size);

	int sum = 0;

	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') break;

		if (index == 0)
		{
			charStack.Push(arr[index]);
		}
		else
		{
			if (charStack.IsEmpty() == false && charStack.Top() == '(' && arr[index] == ')')
			{
				if (arr[index - 1] == '(' && arr[index] == ')') // 바로 괄호가 나오는 경우
				{
				}
				else
				{
				}

				charStack.Pop();

			}
			else if (charStack.IsEmpty() == false && charStack.Top() == '[' && arr[index] == ']')
			{
				if (arr[index - 1] == '[' && arr[index] == ']')
				{
				}
				else
				{
				}

			}
			else
			{
				charStack.Push(arr[index]);
			}
		}

		index++;
	}

	return 0;
}