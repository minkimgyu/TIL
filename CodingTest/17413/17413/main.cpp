#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
	vector<char> _vec;

public:
	void Push(char item)
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

	char Top()
	{
		int size = _vec.size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}
};

// ���ø� ������ �������� ���� ť�� �ᵵ ������ �׳� ����ص� ������� ������ ����

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 100001;
	char* arr = new char[size];

	Stack stack;

	cin.getline(arr, 100001);
	bool printNormal = false;

	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') // ���������� ���� �� ���
		{
			while (stack.Size() > 0)
			{
				cout << stack.Top();
				stack.Pop();
			}
			break;
		}
		else if (arr[index] == '>')
		{
			cout << arr[index];
			index++;
			printNormal = false;
			continue;
		}
		else if (printNormal == true)
		{
			cout << arr[index];
			index++;
			continue;
		}
		else if (arr[index] == '<')
		{
			while (stack.Size() > 0)
			{
				cout << stack.Top();
				stack.Pop();
			}

			cout << arr[index];
			index++;
			printNormal = true;
			continue;
		}
		else if (arr[index] == ' ') // ���ÿ� ���� �� ��� + ' ' ���
		{
			while (stack.Size() > 0)
			{
				cout << stack.Top();
				stack.Pop();
			}

			cout << ' ';
			index++;
			continue;
		}

		stack.Push(arr[index]);
		index++;
	}

	return 0;
}