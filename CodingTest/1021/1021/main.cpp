#include <iostream>
#include <list>
using namespace std;

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

// 2, 3, 4, 5, 6, 7, 8, 9, 10, 1 --> 2 ����
// 
// 3, 4, 5, 6, 7, 8, 9, 10, 1 --> 1 ����
// 
// 1, 3, 4, 5, 6, 7, 8, 9, 10 --> 3 ����
// 10, 1, 3, 4, 5, 6, 7, 8, 9 --> 3 ����
// 9, 10, 1, 3, 4, 5, 6, 7, 8 --> 3 ����

// 10, 1, 3, 4, 5, 6, 7, 8 --> 1 ����

// 8, 10, 1, 3, 4, 5, 6, 7 --> 3 ����
// 7, 8, 10, 1, 3, 4, 5, 6 --> 3 ����
// 6, 7, 8, 10, 1, 3, 4, 5 --> 3 ����
// 5, 6, 7, 8, 10, 1, 3, 4 --> 3 ����

// 6, 7, 8, 10, 1, 3, 4 --> 1 ����


// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

// 2, 3, 4, 5, 6, 7, 8, 9, 10
// 3, 4, 5, 6, 7, 8, 9, 10, 2
// 4, 5, 6, 7, 8, 9, 10, 2, 3
// 5, 6, 7, 8, 9, 10, 2, 3, 4

list<int> items;
int n, m;

void RemoveFirst()
{
	items.pop_front();
	for (list<int>::iterator iter = items.begin(); iter != items.end(); iter++)
	{
		*iter -= 1;
	}
	n -= 1;
}

void Move(int movePoint)
{
	for (list<int>::iterator iter = items.begin(); iter != items.end(); iter++)
	{
		*iter += movePoint;
		if (*iter <= 0)
		{
			*iter += n;
		}
		else if (*iter > n)
		{
			*iter -= n;
		}
	}

	RemoveFirst();
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int item;
		cin >> item;
		items.push_back(item);
	}

	int result = 0;

	for (int i = 0; i < m; i++)
	{
		// �ٷ� ����
		if (items.front() == 1)
		{
			RemoveFirst();
		}
		else
		{
			int goLeftCount = items.front() - 1;
			int goRightCount = n - items.front() + 1;

			if (goLeftCount < goRightCount)
			{
				result += goLeftCount;
				Move(-goLeftCount);
			}
			else
			{
				result += goRightCount;
				Move(goRightCount);
			}
		}
	}

	cout << result;

	return 0;
}