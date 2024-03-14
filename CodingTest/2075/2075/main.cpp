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

		while (GetChildIndex(index, true) <= GetSize() - 1) // ���� �ڽ��� ������ �ε��� ���� �۰ų� ���� ������ ����
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

// ù��° ����: �� �� �ٸ� �켱���� ť�� ���� ���� ū ���� �ι�°�� ū ���� �����ͼ� �� ��°�� ū ���� ���� ���� ���ϴ� ��� --> ���� - �������� Ʋ����
// �ι�° ����: �� �ϳ��� Stack���� ��� �����͸� �����ϰ� �̸� �켱���� ť�� �־ ������ �� �� ���� �ϳ��� ���鼭 ���� --> �޸� �ʰ� - ���ʿ� �̷� ������ �� �����Ѵٴ� ������� �����ϸ� �� �ɵ�?
// ����° ����: �� �� �ٺ��� priorityQueue�� ����ִ´�. �� ���� �ش� ������ ���� ���� ���̹Ƿ� n�� �̻� priorityQueue�� �� ��� �̸� ���ָ鼭 �����Ѵ�.

// �� ������ �������� ���� �����ϸ� �׸��� �˰��� ������� �����غ��°� ���ƺ��� 

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