#include <iostream>
#include <vector>
#include <string>
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

	T Top()
	{
		int size = _vec.size();
		return _vec[size - 1];
	}

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return _vec.size() == 0;
	}

private:
	vector<T> _vec;
};

// 스택을 사용하는 문제
// 해결 방법은 Stack의 Top 그리고 arr[index] 값을 비교해서 {} 이면 스택에서 버림
// 나머지 값들을 2개씩 전부 꺼내서 }{, {} 이런 나열로 되어있으면 +1 해주고 {{, }} 이런 나열로 되어있으면 +2 해줘야한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<char*> _vec;

	while (1)
	{
		const int size = 2001;
		char* tmp = new char[size];
		cin.getline(tmp, size);

		if (tmp[0] == '-') break;

		_vec.push_back(tmp);
	}

	vector<int> values;

	int size = _vec.size();
	for (int i = 0; i < size; i++)
	{
		Stack<char> stack;
		char* arr = _vec[i];
		int index = 0;
		while (1)
		{
			if (arr[index] == '\0') break;

			if(index == 0) stack.Push(arr[index]);
			else
			{
				if (stack.Size() > 0 && (stack.Top() == '{' && arr[index] == '}'))
				{
					stack.Pop();
				}
				else
				{
					stack.Push(arr[index]);
				}
			}
			
			index++;
		}

		int cnt = 0;

		while (stack.IsEmpty() == false)
		{
			char firstItem = stack.Top();
			stack.Pop();
			char secondItem = stack.Top();
			stack.Pop();

			if (firstItem == secondItem) cnt++;
			else cnt += 2;
		}

		values.push_back(cnt);
	}

	int answerSize = values.size();
	for (int i = 0; i < answerSize; i++)
	{
		string tmp = to_string(i + 1) + ". " + to_string(values[i]);

		if (i == answerSize - 1) cout << tmp;
		else cout << tmp << '\n';
	}

	return 0;
}