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

	int Size()
	{
		return _vec.size();
	}

	char Top()
	{
		int size = _vec.size();
		return _vec[size - 1];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack stack;

	// �ð� ���⵵: O(n)���� �ذ� ������
	// �������� �������� ��������

	int size = 100001; // �̰� 100000���̱� ������ '\0' �߰��ؾ��ؼ� 100001�� �����������
	char* arr = new char[size];
	cin >> arr;

	int steelCount = 0;
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '\0') break;

		int size = stack.Size();
		if (size == 0 && arr[i] == '(')
		{
			steelCount++;
			stack.Push(arr[i]);
			continue;
		}

		if (arr[i] == '(')
		{
			steelCount++;
			stack.Push(arr[i]);
		}
		else if (stack.Top() == '(' && arr[i] == ')')
		{
			if (arr[i - 1] == '(') // �������� ���
			{
				steelCount -= 1; // �ֳ��ϸ� ö�̶�� �����ϰ� ������ ���߱� ������
				sum += steelCount;
			}
			else if (arr[i - 1] == ')') // ö�� ���
			{
				steelCount--;
				sum++;
			}
			stack.Pop();
		}
	}

	cout << sum;

	return 0;
}