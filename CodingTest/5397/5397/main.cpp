#include <iostream>
#include <vector>
using namespace std;

class Stack 
{
public:
	void Push(char item)
	{
		_vec.push_back(item);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	int Size()
	{
		return _vec.size();
	}

	char Top()
	{
		int size = Size();
		return _vec[size - 1];
	}

	bool IsEmpty()
	{
		return Size() == 0;
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
	vector<char> _vec;
};

// Stack을 사용하는 문제
// <가 입력되면 스택에서 빼고 >가 입력되면 다시 스텍에 넣는 부분을 잘 알아두기

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 1000001;

	int n;
	cin >> n;

	cin.ignore();

	vector<char*> arrs;

	for (int i = 0; i < n; i++)
	{
		char* arr = new char[size];
		cin.getline(arr, size);

		arrs.push_back(arr);
	}

	for (int i = 0; i < n; i++)
	{
		char* arr = arrs[i];
		Stack mainStack;
		Stack subStack;

		int index = 0;
		while (1)
		{
			if (arr[index] == '\0') break;

			if (arr[index] == '<')
			{
				if (mainStack.IsEmpty() == false)
				{
					char item = mainStack.Top();
					subStack.Push(item);
					mainStack.Pop();
				}
			}
			else if (arr[index] == '>')
			{
				if (subStack.IsEmpty() == false)
				{
					char item = subStack.Top();
					mainStack.Push(item);
					subStack.Pop();
				}
			}
			else if (arr[index] == '-')
			{
				if (mainStack.IsEmpty() == false)
				{
					mainStack.Pop();
				}
			}
			else
			{
				mainStack.Push(arr[index]);
			}

			index++;
		}

		while (subStack.IsEmpty() == false)
		{
			int item = subStack.Top();
			mainStack.Push(item);
			subStack.Pop();
		}

		mainStack.Print();
		if (i != n - 1) cout << '\n';
	}

	return 0;
}