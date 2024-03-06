#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Stack
{
private:
	vector<int> vec;
	int minValue = -1;

public:
	void Pop() { vec.pop_back(); }

	int GetMinValue() { return minValue; }

	void Push(int item) 
	{ 
		vec.push_back(item); 
		if (minValue == -1) minValue = item;
		else if (item < minValue) minValue = item;
	}

	bool IsEmpty() { return vec.size() == 0; }

	int Top() { return vec.back(); }
};


/// <summary>
/// 반례가 중요함!!
/// Stack에 넣은 수도 꺼내서 내보낼 수 있다는 것을 기억해두어야함!!
/// </summary>
/// <returns></returns>
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	list<int> nowLine;
	Stack onlyOneLine;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		nowLine.push_back(tmp);
	}

	int minValue = 1;

	while (true)
	{
		bool isOnlyOneLineEmpty = onlyOneLine.IsEmpty();
		bool isNowLineEmpty = nowLine.size() == 0;

		if (isNowLineEmpty)
		{
			if (isOnlyOneLineEmpty)
			{
				cout << "Nice";
				break;
			}
			else if (onlyOneLine.Top() > minValue)
			{
				cout << "Sad";
				break;
			}
		}

		if (isOnlyOneLineEmpty == false)
		{
			int top = onlyOneLine.Top();
			if (top == minValue)
			{
				onlyOneLine.Pop();
				minValue++;
				continue;
			}
		}

		int front = nowLine.front();
		if (front == minValue)
		{
			minValue++;
		}
		else
		{
			onlyOneLine.Push(front);
		}

		nowLine.pop_front();
	}

	return 0;
}