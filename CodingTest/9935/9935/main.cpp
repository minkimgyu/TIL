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

	int Size() { return _vec.size(); }

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

// 스택을 활용하는 문제
// 거꾸로 문자열을 검사하는 방법을 잘 알아두면 좋다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int arrSize = 1000001;
	char* arr = new char[arrSize];

	const int bombSize = 37;
	char* bombArr = new char[bombSize];

	cin.getline(arr, arrSize);
	cin.getline(bombArr, bombSize);

	int cnt = 0;
	while (1)
	{
		if (bombArr[cnt] == '\0') break;
		cnt++;
	}

	Stack mainStack;

	int index = 0;
	while (1)
	{
		if (arr[index] == '\0') break;

		mainStack.Push(arr[index]);
		int size = mainStack.Size();

		if (size >= cnt) // bombArr의 길이를 넘어간다면 폭탄인지 확인
		{
			Stack tmpStack;
			int bombCheckIndex = 0;
			while (1)
			{
				char top = mainStack.Top();
				mainStack.Pop();
				tmpStack.Push(top);

				if (top != bombArr[(cnt - 1) - bombCheckIndex])
				{
					// 폭탄이 아닌 경우 다시 꺼내서 옮긴다.
					while (tmpStack.Size() > 0)
					{
						char top = tmpStack.Top();
						tmpStack.Pop();
						mainStack.Push(top);
					}
					break;
				}
				else
				{
					// 끝까지 비교해서 맞는 경우
					if (bombCheckIndex == cnt - 1) 
					{
						break; // 탈출
					}
				}
				bombCheckIndex++;
			}
		}

		index++;
	}

	if (mainStack.IsEmpty() == true)
	{
		cout << "FRULA";
		return 0;
	}

	mainStack.Print();
	return 0;
}