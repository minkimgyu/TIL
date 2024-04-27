#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class PriorityQueue
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

	int Size()
	{
		return _vec.size();
	}

	bool IsEmpty()
	{
		return Size() == 0;
	}

private:
	int GetParentIndex(int index) { return (int)((index - 1) / 2); }
	int GetLeftChildIndex(int index) { return 2 * index + 1; }
	int GetRightChildIndex(int index) { return 2 * index + 2; }

	void Swap(int aIndex, int bIndex)
	{
		int a = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = a;
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

	void PercolateDown(int index)
	{
		int currentIndex = index;
		int childIndex = GetLeftChildIndex(currentIndex);
		int rightChildIndex = GetRightChildIndex(currentIndex);

		int size = Size();
		if (rightChildIndex < size && _vec[childIndex] < _vec[rightChildIndex]) childIndex = rightChildIndex;

		while (childIndex < size && _vec[childIndex] > _vec[currentIndex])
		{
			Swap(childIndex, currentIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);

			if (rightChildIndex < size && _vec[childIndex] < _vec[rightChildIndex]) childIndex = rightChildIndex;
		}
	}

private:
	vector<int> _vec;
};

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	pair<int, int>* ramens = new pair<int, int>[n];
	
	int maxDay = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> ramens[i].first >> ramens[i].second;
		if (ramens[i].first > maxDay) maxDay = ramens[i].first;
	}

	sort(ramens, ramens + n, compare);

	PriorityQueue pQ;

	int sum = 0;
	int index = 0;
	for (int i = maxDay; i > 0 ; i--)
	{
		while (index < n && ramens[index].first >= i)
		{
			pQ.Insert(ramens[index].second);
			index++;
		}

		if (pQ.IsEmpty() == true) continue;

		int reward = pQ.GetMax();
		pQ.DeleteMax();
		sum += reward;
	}

	cout << sum;
	return 0;
}