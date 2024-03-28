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

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Size()
	{
		return _vec.size();
	}

private:
	vector<T> _vec;
};


// Stack을 활용한 문제
// 남은 괄호의 개수 = 답
// 위 사항을 이해하고 있다면 쉽게 풀 수 있는 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<char> stack;

	const int size = 51;
	char arr[size];

	cin.getline(arr, size);

	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') break;

		if (index == 0) stack.Push(arr[index]);
		else
		{
			if (stack.Top() == '(' && arr[index] == ')')
			{
				stack.Pop();
			}
			else
			{
				stack.Push(arr[index]);
			}
		}

		index++;
	}

	cout << stack.Size();

	return 0;
}