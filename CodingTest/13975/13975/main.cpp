#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
	int GetParentIndex(int index)
	{
		return (int)((index - 1) / 2);
	}

	int GetLeftChildIndex(int index)
	{
		return (2 * index) + 1;
	}

	int GetRightChildIndex(int index)
	{
		return (2 * index) + 2;
	}

	void Swap(int aIndex, int bIndex)
	{
		int tmp = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = tmp;
	}
	
	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);
		int size = Size();

		if (rightChildIndex < size && _vec[childIndex] > _vec[rightChildIndex])
		{
			childIndex = rightChildIndex;
		}

		while (childIndex < size && _vec[currentIndex] > _vec[childIndex])
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex] > _vec[rightChildIndex])
			{
				childIndex = rightChildIndex;
			}
		}
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (parentIndex >= 0 && _vec[parentIndex] > _vec[currentIndex])
		{
			Swap(parentIndex, currentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

public:
	void Insert(long long int item)
	{
		_vec.push_back(item);
		int size = Size();

		PercolateUp(size - 1);
	}

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

	void DeleteMin()
	{
		int size = Size();
		_vec[0] = _vec[size - 1];
		_vec.pop_back();

		PercolateDown(0);
	}

	long long int GetMin()
	{
		return _vec[0];
	}

private:
	vector<long long int> _vec;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	vector<long long int> resultArr;

	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;

		PriorityQueue pQ;
		for (int j = 0; j < k; j++)
		{
			int tmp;
			cin >> tmp;

			pQ.Insert(tmp);
		}

		long long int finalSum = 0;

		while (pQ.Size() > 1)
		{
			long long int a = pQ.GetMin();
			pQ.DeleteMin();

			long long int b = pQ.GetMin();
			pQ.DeleteMin();

			long long int sum = a + b;
			pQ.Insert(sum);

			finalSum += sum;
		}

		resultArr.push_back(finalSum);
	}

	int size = resultArr.size();
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) cout << resultArr[i];
		else cout << resultArr[i] << '\n';
	}

	return 0;
}