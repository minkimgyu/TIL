#include <iostream>
#include <vector>
using namespace std;

struct Item
{
public:
	char value;
	int index;
};

class Stack
{
public:
	void Push(Item item)
	{
		_vec.push_back(item);
	}

	void Pop()
	{
		_vec.pop_back();
	}

	Item Top()
	{
		int size = Size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}

	Item ReturnItemUsingIndex(int index)
	{
		return _vec[index];
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	vector<Item> _vec;
};

// https://www.acmicpc.net/board/view/78524
// 위 풀이를 참고함

// 스택에서 뺄 때 아래에 쌓인 값을 전부 곱해주면 되는 문제
// 만약 괄호가 바로 닫히지 않는 경우(인덱스가 이어지지 않았을 경우) 이 경우는 계산에 넣지말고 바로 빼줘야한다.
// 모든 계산이 끝났는데 스택에 남은 값이 있다면 입력이 잘못된 경우이므로 0를 출력해준다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack stack;

	const int size = 31;

	char arr[size];
	cin.getline(arr, size);

	int sum = 0;

	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') break;

		if (index == 0)
		{
			Item item;
			item.index = index;
			item.value = arr[index];

			stack.Push(item);
		}
		else
		{
			if (stack.IsEmpty() == false && stack.Top().value == '(' && arr[index] == ')')
			{
				if (index - stack.Top().index == 1) // 바로 이전 값인 경우만 --> 괄호가 붙어있는 경우만
				{
					stack.Pop();
					int tmp = 2;

					int size = stack.Size();
					if (size > 0)
					{
						for (int i = 0; i < size; i++)
						{
							char item = stack.ReturnItemUsingIndex(i).value;
							if (item == '(') tmp *= 2;
							else if (item == '[') tmp *= 3;
						}

						
					}

					sum += tmp;
				}
				else
				{
					stack.Pop();
				}
			}
			else if (stack.IsEmpty() == false && stack.Top().value == '[' && arr[index] == ']')
			{
				if (index - stack.Top().index == 1) // 바로 이전 값인 경우만 --> 괄호가 붙어있는 경우만
				{
					stack.Pop();
					int tmp = 3;

					int size = stack.Size();
					if (size > 0)
					{
						for (int i = 0; i < size; i++)
						{
							char item = stack.ReturnItemUsingIndex(i).value;
							if (item == '(') tmp *= 2;
							else if (item == '[') tmp *= 3;
						}
					}

					sum += tmp;
				}
				else
				{
					stack.Pop();
				}
			}
			else
			{
				Item item;
				item.index = index;
				item.value = arr[index];

				stack.Push(item);
			}
		}

		index++;
	}

	if (stack.IsEmpty() == false) cout << 0; // 만약 제대로 처리되지 않아서 남은 값이 있다면
	else cout << sum;

	return 0;
}