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
		return 2 * index + 1;
	}

	int GetRightChildIndex(int index)
	{
		return 2 * index + 2;
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
			Swap(currentIndex, parentIndex);

			currentIndex = parentIndex;
			parentIndex = GetParentIndex(parentIndex);
		}
	}

public:
	void Insert(int item)
	{
		_vec.push_back(item);

		int size = _vec.size();
		PercolateUp(size - 1);
	}

	void DeleteMin()
	{
		int size = _vec.size();
		_vec[0] = _vec[size - 1];
		_vec.pop_back();

		PercolateDown(0);
	}

	int Size()
	{
		return _vec.size();
	}

	int GetMin()
	{
		return _vec[0];
	}

private:
	vector<int> _vec;
};

// 예제 출력을 보고 작은 수를 계속 빼서 더하면 끝나는 문제라고 생각했는데
// 4 1 1 1 1
// 이라는 예제 케이스를 보고 가장 작은 2개의 수를 빼서 더하고 다시 큐에 넣는 것을 반복하는 방식을 찾게되었다.

// 우선순위 큐는 이제 구현 잘 하는 듯...
// 그리디를 이용하는 문제인 만큼 한번 다시 돌아볼 필요가 있을 것 같다.


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	PriorityQueue pQ;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		pQ.Insert(tmp);
	}

	int sum = 0;
	
	while (pQ.Size() >= 2) // 2개씩 빼서 1개를 다시 넣는다면 결과적으로 1개만 남게된다.
	{
		int first = pQ.GetMin();
		pQ.DeleteMin();

		int second = pQ.GetMin();
		pQ.DeleteMin();

		int item = first + second;

		pQ.Insert(item);
		sum += item;
	}

	cout << sum;

	return 0;
}