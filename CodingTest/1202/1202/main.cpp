#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Diamond
{
public:
	int _weight;
	int _price;
};

struct Bag
{
public:
	int _emptySpace;
	bool _isFull = false;
};

class PriorityQueue
{
public:
	void Insert(Diamond* diamond)
	{
		_vec.push_back(diamond);
		int size = Size();

		PercolateUp(size - 1);
	}

	Diamond* GetMax()
	{
		return _vec[0];
	}

	void DeleteMax()
	{
		int size = Size();
		_vec[0] = _vec[size - 1];
		_vec.pop_back();

		PercolateDown(0);
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

	void Swap(int aIndex, int bIndex)
	{
		Diamond* a = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = a;
	}

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(index);
		int rightChildIndex = GetRightChildIndex(index);

		int size = Size();
		if (rightChildIndex < size && _vec[childIndex]->_price < _vec[rightChildIndex]->_price) childIndex = rightChildIndex;

		while (childIndex < size && _vec[currentIndex]->_price < _vec[childIndex]->_price)
		{
			Swap(childIndex, currentIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex]->_price < _vec[rightChildIndex]->_price) childIndex = rightChildIndex;
		}
	}

	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (parentIndex >= 0 && _vec[parentIndex]->_price < _vec[currentIndex]->_price)
		{
			Swap(parentIndex, currentIndex);
			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}


private:
	vector<Diamond*> _vec;
};

bool compare1(Diamond a, Diamond b)
{
	return a._weight < b._weight;
}

bool compare2(Bag a, Bag b)
{
	return a._emptySpace < b._emptySpace;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	Diamond* diamonds = new Diamond[n];
	Bag* bags = new Bag[k];

	for (int i = 0; i < n; i++)
	{
		cin >> diamonds[i]._weight >> diamonds[i]._price;
	}

	for (int i = 0; i < k; i++)
	{
		cin >> bags[i]._emptySpace;
	}

	sort(diamonds, diamonds + n, compare1);
	sort(bags, bags + k, compare2);

	long long int sum = 0;
	PriorityQueue pQ;

	int index = 0;
	for (int i = 0; i < k; i++)
	{
		// 이렇게 하면 시간 복잡도가 n * k가 아니라 n + k가 된다.
		while (index < n && bags[i]._emptySpace >= diamonds[index]._weight)
		{
			pQ.Insert(&diamonds[index]);
			index++;
		}

		if (pQ.IsEmpty() == true) continue;

		Diamond* dia = pQ.GetMax();
		pQ.DeleteMax();
		sum += dia->_price;
	}

	cout << sum;

	return 0;
}