#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
public:
	void Insert(int item)
	{
		_vec.push_back(item);
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

	int GetMin()
	{
		return _vec[0];
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Size()
	{
		return _vec.size();
	}

private:
	int GetParentIndex(int index) { return (int)((index - 1) / 2); }

	int GetLeftChildIndex(int index) { return (2 * index) + 1; }

	int GetRightChildIndex(int index) { return (2 * index) + 2; }

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[rightChildIndex] < _vec[childIndex]) childIndex = rightChildIndex;

		while (childIndex < size && _vec[childIndex] < _vec[currentIndex])
		{
			Swap(childIndex, currentIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[rightChildIndex] < _vec[childIndex]) childIndex = rightChildIndex;
		}
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (parentIndex >= 0 && _vec[currentIndex] < _vec[parentIndex])
		{
			Swap(parentIndex, currentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

	void Swap(int aIndex, int bIndex)
	{
		int a = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = a;
	}

private:
	vector<int> _vec;
};

class MaxHeap
{
public:
	void Insert(int item)
	{
		_vec.push_back(item);
		int size = Size();
		PercolateUp(size - 1);
	}

	void DeleteMax()
	{
		int size = Size();
		_vec[0] = _vec[size - 1];
		_vec.pop_back();

		PercolateDown(0);
	}

	int GetMax()
	{
		return _vec[0];
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	int Size()
	{
		return _vec.size();
	}

private:
	int GetParentIndex(int index) { return (int)((index - 1) / 2); }

	int GetLeftChildIndex(int index) { return (2 * index) + 1; }

	int GetRightChildIndex(int index) { return (2 * index) + 2; }

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[rightChildIndex] > _vec[childIndex]) childIndex = rightChildIndex;

		while (childIndex < size && _vec[childIndex] > _vec[currentIndex])
		{
			Swap(childIndex, currentIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[rightChildIndex] > _vec[childIndex]) childIndex = rightChildIndex;
		}
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (parentIndex >= 0 && _vec[currentIndex] > _vec[parentIndex])
		{
			Swap(parentIndex, currentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

	void Swap(int aIndex, int bIndex)
	{
		int a = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = a;
	}

private:
	vector<int> _vec;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	MaxHeap maxHeap;
	MinHeap minHeap;
	vector<int> results;

	

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int item;
		cin >> item;

		// 3, 1
		// 4, 2
		// 5, 3
		// 같은 케이스 --> 왼쪽에서 하나 빼고 오른쪽에 넣으면 양쪽의 수의 개수가 같아지는 경우
		// 이유는 총 개수가 홀수인 경우, 즉 (2, 1), (3, 2) 같은 경우는 maxHeap의 max를 출력하면 되기 때문이다. 

		maxHeap.Insert(item);
		if (maxHeap.Size() - minHeap.Size() >= 2)
		{
			int max = maxHeap.GetMax();
			maxHeap.DeleteMax();
			minHeap.Insert(max);
		}

		if (minHeap.IsEmpty() == false && maxHeap.IsEmpty() == false)
		{
			if (minHeap.GetMin() < maxHeap.GetMax())
			{
				int max = maxHeap.GetMax();
				maxHeap.DeleteMax();

				int min = minHeap.GetMin();
				minHeap.DeleteMin();

				maxHeap.Insert(min);
				minHeap.Insert(max);
			}
		}

		int middle = maxHeap.GetMax();
		results.push_back(middle);
	}

	int size = results.size();
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) cout << results[i];
		else cout << results[i] << '\n';
	}

	return 0;
}