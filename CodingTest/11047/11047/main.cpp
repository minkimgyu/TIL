#include <iostream>
#include <vector>
using namespace std;

class Stack
{
public:
	void Push(int item)
	{
		_vec.push_back(item);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	int Top()
	{
		int size = Size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}

private:
	vector<int> _vec;
};

// 가장 큰 숫자부터 시작해서 빼주면 되는 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	Stack stack;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		stack.Push(tmp);
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (k == 0) break;

		int item = stack.Top();
		if (k < item)
		{
			stack.Pop();
			continue;
		}

		count += (int)k / item;

		k %= item;
		stack.Pop();
	}

	cout << count;

	return 0;
}