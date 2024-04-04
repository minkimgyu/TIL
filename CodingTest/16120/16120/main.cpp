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
		return Size() == 0;
	}

	bool HasPPAP()
	{
		int size = Size();
		if (_vec[size - 1] == 'P' && _vec[size - 2] == 'A' && _vec[size - 3] == 'P' && _vec[size - 4] == 'P') return true;
		return false;
	}

private:
	vector<T> _vec;
};

// 스택을 사용하는 문제
// PPAP를 만나면 Pop 해준다.
// 결과적으로 마지막에 P만 남으면 참
// 아니면 거짓임

const int arrSize = 1000001;
char arr[arrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<char> stack;
	cin.getline(arr, arrSize);

	int index = 0;
	while (1)
	{
		if (stack.Size() >= 4)
		{
			bool hasPPAP = stack.HasPPAP();
			if (hasPPAP == true)
			{
				stack.Pop();
				stack.Pop();
				stack.Pop();
				stack.Pop();

				stack.Push('P');
			}
		}

		if (arr[index] == '\0')
		{
			if (stack.Size() == 1 && stack.Top() == 'P') cout << "PPAP";
			else cout << "NP";

			break;
		}

		stack.Push(arr[index]);
		index++;
	}

	return 0;
}