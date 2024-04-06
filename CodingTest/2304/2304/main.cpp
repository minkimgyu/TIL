#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Pillar
{
public:
	int _index, _top = 0;
	bool _canResetMax = false;
};

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

	int Size()
	{
		return _vec.size();
	}

	T Top()
	{
		int size = Size() - 1;
		return _vec[size];
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	vector<T> _vec;
};

bool compare(Pillar a, Pillar b)
{
	return a._index < b._index;
}

// 정렬하고 Stack에 넣고 꺼내면서 푸는 문제
// 같은 최대값 처리와 스택에 넣는 과정이 중요함
// 스택에 넣을 때 앞선 작은 것들은 다 꺼내버려야함
// 여기서 중요한 점은 max를 경신한 경우는 꺼내지 않고 계속 두어야 한다는 것임

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Pillar* pillars;
	Stack<Pillar> stack;

	int n;
	cin >> n;

	pillars = new Pillar[n];

	for (int i = 0; i < n; i++)
	{
		int index, top;
		cin >> index >> top;

		Pillar pillar;
		pillar._index = index;
		pillar._top = top;

		pillars[i] = pillar;
	}

	sort(pillars, pillars + n, compare);

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		while (stack.IsEmpty() == false)
		{
			int top = stack.Top()._top;
			bool canResetMax = stack.Top()._canResetMax;
			if (top < pillars[i]._top && canResetMax == false)
			{
				stack.Pop();
			}
			else break;
		}

		if (pillars[i]._top >= max)
		{
			max = pillars[i]._top;
			pillars[i]._canResetMax = true;
		}

		stack.Push(pillars[i]);
	}

	int sum = 0;

	while (1)
	{
		Pillar backPilar = stack.Top();
		stack.Pop();

		if (stack.IsEmpty() == true) break;

		Pillar frontPilar = stack.Top();

		int width = backPilar._index - frontPilar._index;

		if (frontPilar._top >= backPilar._top) sum += width * backPilar._top;
		else sum += width * frontPilar._top;
	}

	sum += max;

	cout << sum;

	return 0;
}