#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UseTime
{
public:
	int _startTime, _endTime;
	int _seatNum;
};

class IntPriorityQueue
{
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

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[childIndex] > _vec[rightChildIndex]) childIndex = rightChildIndex; // 더 작은 값으로 교체해준다.

		while (childIndex < size && _vec[childIndex] < _vec[currentIndex])
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex] > _vec[rightChildIndex]) childIndex = rightChildIndex; // 더 작은 값으로 교체해준다.
		}
	}

	void Swap(int i, int j)
	{
		int tmp = _vec[i];
		_vec[i] = _vec[j];
		_vec[j] = tmp;
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(index);


		while (parentIndex >= 0 && _vec[parentIndex] > _vec[currentIndex])
		{
			Swap(currentIndex, parentIndex);
			currentIndex = parentIndex;
			parentIndex = GetParentIndex(parentIndex);
		}
	}

public:
	int Size()
	{
		return _vec.size();
	}

	int GetMin()
	{
		return _vec[0];
	}

	void Insert(int item)
	{
		_vec.push_back(item);
		int size = Size();

		PercolateUp(size - 1);
	}

	void DeleteMin()
	{
		int size = Size();
		_vec[0] = _vec[size - 1]; // 마지막 값과 스왑
		_vec.pop_back();

		PercolateDown(0); // 0번 인덱스부터 PercolateDown 진행
	}

private:
	vector<int> _vec;
};


class PriorityQueue
{
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

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[childIndex]._endTime > _vec[rightChildIndex]._endTime) childIndex = rightChildIndex; // 더 작은 값으로 교체해준다.

		while (childIndex < size && _vec[childIndex]._endTime < _vec[currentIndex]._endTime)
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex]._endTime > _vec[rightChildIndex]._endTime) childIndex = rightChildIndex; // 더 작은 값으로 교체해준다.
		}
	}

	void Swap(int i, int j)
	{
		UseTime tmp = _vec[i];
		_vec[i] = _vec[j];
		_vec[j] = tmp;
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while(parentIndex >= 0 && _vec[parentIndex]._endTime > _vec[currentIndex]._endTime)
		{
			Swap(currentIndex, parentIndex);
			currentIndex = parentIndex;
			parentIndex = GetParentIndex(parentIndex);
		}
	}

public:
	int Size()
	{
		return _vec.size();
	}

	UseTime GetMin()
	{
		return _vec[0];
	}

	void Insert(UseTime item)
	{
		_vec.push_back(item);
		int size = Size();

		PercolateUp(size - 1);
	}

	void DeleteMin()
	{
		int size = Size();
		_vec[0] = _vec[size - 1]; // 마지막 값과 스왑
		_vec.pop_back();

		PercolateDown(0); // 0번 인덱스부터 PercolateDown 진행
	}

private:
	vector<UseTime> _vec;
};

bool compare(UseTime a, UseTime b)
{
	if (a._startTime < b._startTime) return true;
	return false;
}

int sitCount[100005]{ 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	UseTime* useTime = new UseTime[n];
	for (int i = 0; i < n; i++)
	{
		cin >> useTime[i]._startTime >> useTime[i]._endTime;
	}

	sort(useTime, useTime + n, compare);

	PriorityQueue pQ;
	int maxSize = 0;

	IntPriorityQueue container;


	for (int i = 0; i < n; i++)
	{
		int seatNum = maxSize;

		if (i > 0)
		{
			while (pQ.Size() > 0 && pQ.GetMin()._endTime < useTime[i]._startTime)
			{
				UseTime MinEndUseTime = pQ.GetMin();

				container.Insert(MinEndUseTime._seatNum);
				pQ.DeleteMin();
			}

			if (container.Size() > 0) // 컨테이너에 가지고 있는 값이 있다면
			{
				seatNum = container.GetMin(); // 그중에서 최소 값을 사용한다.
				container.DeleteMin();
			}

			// 아니면 pQ.Size()를 사용함
		}

		useTime[i]._seatNum = seatNum;
		sitCount[seatNum] += 1;
		pQ.Insert(useTime[i]);
		
		int size = pQ.Size();
		if (maxSize < size) maxSize = size;
	}

	cout << maxSize << '\n';
	for (int i = 0; i < maxSize; i++)
	{
		if (i == maxSize - 1) cout << sitCount[i];
		else cout << sitCount[i] << " ";
	}

	return 0;
}