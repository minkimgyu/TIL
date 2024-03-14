#include <iostream>
#include <vector>
#include <list>
using namespace std;

//struct Stack
//{
//public:
//	int GetTop() { return _vec.back(); }
//
//	void Push(int item) { return _vec.push_back(item); }
//	void Pop() { return _vec.pop_back(); }
//
//private:
//	vector<int> _vec;
//};

class PriorityQueue
{
private:
	vector<int> _vec;

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

	void percolateUp(int startIndex)
	{
		int itemIndex = startIndex;
		int parentIndex = GetParentIndex(itemIndex);

		while (itemIndex > 0 && _vec[parentIndex] > _vec[itemIndex])
		{
			int tmp = _vec[parentIndex];
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
				int tmp = _vec[index];
				_vec[index] = _vec[childIndex];
				_vec[childIndex] = tmp;
			}

			index = childIndex;
		}
	}

public:
	void Insert(int item)
	{
		_vec.push_back(item);
		percolateUp(GetSize() - 1);
	}

	int GetSize() { return _vec.size(); }

	int GetMin() { return _vec[0]; }

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
		int tmp = _vec[0];
		_vec[0] = _vec[GetSize() - 1];
		_vec.pop_back();

		percolateDown(0);
	}
};

// 첫번째 접근: 맨 뒷 줄만 우선순위 큐로 묶고 가장 큰 값과 두번째로 큰 값을 가져와서 두 번째로 큰 값의 세로 열을 비교하는 방법 --> 실패 - 논리적으로 틀렸음
// 두번째 접근: 열 하나를 Stack으로 묶어서 데이터를 저장하고 이를 우선순위 큐에 넣어서 스택의 맨 위 값을 하나씩 빼면서 접근 --> 메모리 초과 - 애초에 이런 문제는 다 저장한다는 방식으로 접근하면 안 될듯?
// 세번째 접근: 맨 앞 줄부터 priorityQueue에 집어넣는다. 그 값은 해당 열에서 가장 작은 값이므로 n개 이상 priorityQueue에 들어갈 경우 이를 빼주면서 접근한다.

// 다 저장할 생각하지 말고 가능하면 그리디 알고리즘 방식으로 생각해보는게 좋아보임 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	PriorityQueue priorityQueue;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			cin >> tmp;

			priorityQueue.Insert(tmp);
			if (priorityQueue.GetSize() > n) priorityQueue.Remove();
		}
	}

	cout << priorityQueue.GetMin();

	return 0;
}