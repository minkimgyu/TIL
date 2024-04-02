﻿#include <iostream>
#include <vector>
using namespace std;

class Building
{
public:
	int _top = 0;
	long long int _sum = 0;
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

private:
	vector<T> _vec;
};

// 스택을 활용하는 문제
// 시간 초과가 나므로(최대 O(N^2)) 앞의 건물을 빼면서 작업하는 것이 중요함
// 더 중요한 것은 최대 합이 1부터 80,000까지 더한 값인 3,200,040,000이 나오기 때문에
// long long int로 바꿔줘야한다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack<Building> mainStack;

	int n;
	cin >> n;

	int cnt = 0;
	long long int sum = 0;

	int* arr = new int[n];

	for (int i = n - 1; i >= 0; i--)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			Building building;
			building._top = arr[i];
			building._sum = 0;

			mainStack.Push(building);
		}
		else // 1 2 2
		{
			Building building;
			long long int nowSum = 0;

			// 바로 앞이 본인보다 작다면 다 버리고 버린 만큼 +1
			while (mainStack.IsEmpty() == false && mainStack.Top()._top < arr[i])
			{
				Building top = mainStack.Top();
				mainStack.Pop();

				nowSum += (long long int)1 + top._sum;
			}

			building._sum = nowSum;
			building._top = arr[i];

			mainStack.Push(building);
			sum += nowSum;
		}
	}

	cout << sum;

	return 0;
}