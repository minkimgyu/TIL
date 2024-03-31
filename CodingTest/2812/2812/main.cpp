#include <iostream>
#include <vector>
using namespace std;

template<typename T>
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

	int Size()
	{
		return _vec.size();
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

int ConvertCharToInt(char item)
{
	return (int)item - (int)'0';
}

// Stack을 활용하는 문제
// 처음 접근은 좋았으나 반례를 꼭 한번쯤 생각해보는게 좋을 듯
// 만약 모든 숫자가 같거나 정렬이 내림차순으로 되어있을 경우는 남는 popCnt만큼
// stack를 pop해줘야한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	cin.ignore();

	int size = n + 1;

	char* value = new char[size];
	cin.getline(value, size);

	Stack<char> stack;
	int popCnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)stack.Push(value[i]);
		else
		{
			if (popCnt < k)
			{
				int top = ConvertCharToInt(stack.Top());
				int item = ConvertCharToInt(value[i]);

				while (stack.IsEmpty() == false)
				{
					if (popCnt >= k) break;

					if (top < item)
					{
						stack.Pop();
						popCnt++;
						if (stack.IsEmpty() == false)
							top = ConvertCharToInt(stack.Top());
					}
					else
					{
						break;
					}
				}
				
			}

			stack.Push(value[i]);
		}
	}

	for (int i = 0; i < k - popCnt; i++)
	{
		stack.Pop();
	}

	stack.Print();
	return 0;
}