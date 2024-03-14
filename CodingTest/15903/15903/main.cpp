#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
	vector<long long> _vec;

private:
	int GetParentIndex(int index)
	{
		return ((index - 1) / 2.0f);
	}

	int GetChildIndex(int index, bool isLeft)
	{
		int tmp = 1;
		if (isLeft == false) tmp = 2;

		return index * 2 + tmp;
	}

	int GetSize() { return _vec.size(); }

	void percolateUp(int startIndex)
	{
		int itemIndex = startIndex;
		int parentIndex = GetParentIndex(itemIndex);

		while (itemIndex > 0 && _vec[parentIndex] > _vec[itemIndex])
		{
			long long tmp = _vec[parentIndex];
			_vec[parentIndex] = _vec[itemIndex];
			_vec[itemIndex] = tmp;

			itemIndex = parentIndex;
			parentIndex = GetParentIndex(parentIndex);
		}
	}

	void percolateDown(int startIndex)
	{
		int index = startIndex;
		int childIndex = 0;

		while (GetChildIndex(index, true) <= GetSize() - 1) // 왼쪽 자식이 마지막 인덱스 보다 작거나 같은 경우까지 진행
		{
			childIndex = GetChildIndex(index, true);
			int rightChildIndex = GetChildIndex(index, false);

			if (GetSize() - 1 >= rightChildIndex && _vec[childIndex] > _vec[rightChildIndex]) childIndex = rightChildIndex;

			if (_vec[index] > _vec[childIndex])
			{
				long long tmp = _vec[index];
				_vec[index] = _vec[childIndex];
				_vec[childIndex] = tmp;
			}

			index = childIndex;
		}
	}

public:
	void Insert(long long int item)
	{
		_vec.push_back(item);
		percolateUp(GetSize() - 1);
	}

	long long GetSum()
	{
		long long sum = 0;
		int size = _vec.size();
		for (int i = 0; i < size; i++) 
		{ 
			sum += _vec[i]; 
		}

		return sum;
	}

	long long GetValueUsingIndex(int index) { return _vec[index]; }

	void SetValueUsingIndex(int index, long long value) { _vec[index] = value; }

	int GetMinChildIndexOfTop()
	{
		if (GetSize() == 2) { return 1; } // 왼쪽 값을 반환한다.

		int leftValue = GetChildIndex(0, true);
		int rightValue = GetChildIndex(0, false);

		if (_vec[leftValue] < _vec[rightValue]) return 1;
		else return 2;
	}

	long long GetMin() { return _vec[0]; }

	bool IsEmpty() { return _vec.size() == 0; }

	void BuildHeap()
	{
		int haveChildIndex = GetParentIndex(GetSize() - 1);
		for (int i = haveChildIndex; i >= 0; i--)
		{
			percolateDown(i);
		}
	}

	void Remove()
	{
		_vec[0] = _vec[GetSize() - 1];
		_vec.pop_back();

		percolateDown(0);
	}
};

// 범위가 충분히 크기때문에 long long으로 처리
// index의 경우 int로 처리해야 안 틀림
// 시간 복잡도: n * log(n) + m * log(n)
// (n + m)log(n)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	PriorityQueue priorityQueue;

	int cardCount, mergeCount;
	cin >> cardCount >> mergeCount;

	for (int i = 0; i < cardCount; i++)
	{
		int tmp;
		cin >> tmp;
		priorityQueue.Insert(tmp);
	}

	for (int i = 0; i < mergeCount; i++)
	{
		long long min = priorityQueue.GetMin();

		int childIndex = priorityQueue.GetMinChildIndexOfTop();
		long long childValue = priorityQueue.GetValueUsingIndex(childIndex);
		long long sum = min + childValue;

		priorityQueue.SetValueUsingIndex(0, sum);
		priorityQueue.SetValueUsingIndex(childIndex, sum);

		if (i == mergeCount - 1) break;
		priorityQueue.BuildHeap(); // 다시 힙으로 만들어준다.
	}

	cout << priorityQueue.GetSum();
	
	return 0;
}