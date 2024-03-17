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

	// 시간 복잡도: O(n)으로 해결 가능함
	// 레이저를 기준으로 구해주자

	int size = 100001; // 이거 100000개이기 때문에 '\0' 추가해야해서 100001로 선언해줘야함
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
			if (arr[i - 1] == '(') // 레이저인 경우
			{
				steelCount -= 1; // 왜냐하면 철이라고 생각하고 위에서 더했기 때문에
				sum += steelCount;
			}
			else if (arr[i - 1] == ')') // 철인 경우
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