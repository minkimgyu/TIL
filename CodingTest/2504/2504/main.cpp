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
// �� Ǯ�̸� ������

// ���ÿ��� �� �� �Ʒ��� ���� ���� ���� �����ָ� �Ǵ� ����
// ���� ��ȣ�� �ٷ� ������ �ʴ� ���(�ε����� �̾����� �ʾ��� ���) �� ���� ��꿡 �������� �ٷ� ������Ѵ�.
// ��� ����� �����µ� ���ÿ� ���� ���� �ִٸ� �Է��� �߸��� ����̹Ƿ� 0�� ������ش�.

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
				if (index - stack.Top().index == 1) // �ٷ� ���� ���� ��츸 --> ��ȣ�� �پ��ִ� ��츸
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
				if (index - stack.Top().index == 1) // �ٷ� ���� ���� ��츸 --> ��ȣ�� �پ��ִ� ��츸
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

	if (stack.IsEmpty() == false) cout << 0; // ���� ����� ó������ �ʾƼ� ���� ���� �ִٸ�
	else cout << sum;

	return 0;
}