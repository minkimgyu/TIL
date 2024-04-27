#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Lecture
{
	int _day;
	int _pay;
};

class PriorityQueue
{
public:
	void Insert(Lecture* item)
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

	Lecture* GetMax()
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
		Lecture* item = _vec[aIndex];
		_vec[aIndex] = _vec[bIndex];
		_vec[bIndex] = item;
	}
	
	void PercolateUp(int index)
	{
		int currentIndex = index;
		int parentIndex = GetParentIndex(currentIndex);

		while (parentIndex >= 0 && _vec[currentIndex]->_pay > _vec[parentIndex]->_pay)
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
		if (rightChildIndex < size && _vec[childIndex]->_pay < _vec[rightChildIndex]->_pay) childIndex = rightChildIndex;

		while (childIndex < size && _vec[currentIndex]->_pay < _vec[childIndex]->_pay)
		{
			Swap(currentIndex, childIndex);

			currentIndex = childIndex;
			childIndex = GetLeftChildIndex(currentIndex);
			rightChildIndex = GetRightChildIndex(currentIndex);
			if (rightChildIndex < size && _vec[childIndex]->_pay < _vec[rightChildIndex]->_pay) childIndex = rightChildIndex;
		}
	}

private:
	vector<Lecture*> _vec;
};

bool compare(Lecture a, Lecture b)
{
	if (a._day == b._day) return a._pay < b._pay;
	return a._day > b._day;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int maxDay = 0;
	Lecture* lectures = new Lecture[n];
	for (int i = 0; i < n; i++)
	{
		cin >> lectures[i]._pay >> lectures[i]._day;
		if (maxDay < lectures[i]._day) maxDay = lectures[i]._day;
	}
	
	sort(lectures, lectures + n, compare);

	PriorityQueue pQ;
	int index = 0;
	int sum = 0;

	for (int i = maxDay; i > 0; i--)
	{
		while (index < n && lectures[index]._day >= i)
		{
			pQ.Insert(&lectures[index]);
			index++;
		}

		if (pQ.IsEmpty()) continue;

		Lecture* lecture = pQ.GetMax();
		pQ.DeleteMax();
		sum += lecture->_pay;
	}

	cout << sum;

	return 0;
}