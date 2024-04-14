#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Lesson
{
public:
	int _startTime, _endTime;
};

bool Compare(Lesson a, Lesson b)
{
	if (a._startTime == b._startTime)
	{
		return a._endTime < b._endTime;
	}
	else
	{
		return a._startTime < b._startTime;
	}
}

class PriorityQueue
{
public:
	void Insert(Lesson lesson)
	{
		_vec.push_back(lesson);
		int size = Size();

		PercolateUp(size - 1);
	}

	void DeleteMin()
	{
		int size = Size();
		_vec[0] = _vec[size - 1];
		_vec.pop_back();

		PercolateDown(0);
	}
	
	Lesson GetMin()
	{
		return _vec[0];
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
	int GetParentIndex(int index)
	{
		return (int)((index - 1) / 2);
	}

	int GetLeftChildIndex(int index)
	{
		return 2 * index + 1;
	}

	int GetRightChildIndex(int index)
	{
		return 2 * index + 2;
	}

	void Swap(int a, int b)
	{
		Lesson tmp = _vec[a];
		_vec[a] = _vec[b];
		_vec[b] = tmp;
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(index);

		while (parentIndex >= 0 && _vec[parentIndex]._endTime > _vec[currentIndex]._endTime)
		{
			Swap(currentIndex, parentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(parentIndex); // 이 부분 주의! index가 아니라 parentIndex임
		}
	}

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[childIndex]._endTime > _vec[rightChildIndex]._endTime)
		{
			childIndex = rightChildIndex;
		}

		while (childIndex < size && _vec[currentIndex]._endTime > _vec[childIndex]._endTime)
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;

			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex]._endTime > _vec[rightChildIndex]._endTime)
			{
				childIndex = rightChildIndex;
			}
		}
	}


private:
	vector<Lesson> _vec;
};

// 또 pQ 구현 요류....
// 문제 접근은 잘 했다.

// 이전에 풀었던 준하 문제와 매우 유사한 방식으로 풀이하면 된다.

// 시작 시작 기준으로 먼저 정렬하고
// pQ 구현해서 끝나는 시간 기준으로 정렬해서 끝나는 시간보다 시작 시간이 빠르면 빼준다.
// 계속 반복하면서 최종적으로 maxSize 값을 구하면 되는 문제

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	Lesson* lessons = new Lesson[n];
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		lessons[i]._startTime = start;
		lessons[i]._endTime = end;
	}

	sort(lessons, lessons + n, Compare);

	PriorityQueue pQ;
	int maxSize = 0;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			pQ.Insert(lessons[i]);
		}
		else
		{
			while (pQ.Size() > 0 &&  pQ.GetMin()._endTime <= lessons[i]._startTime)// 교체해야하는 타이밍
			{
				pQ.DeleteMin();
			}

			pQ.Insert(lessons[i]);
		}

		int pQSize = pQ.Size();
		if (maxSize < pQSize) maxSize = pQSize;
	}

	cout << maxSize;

	return 0;
}