#include <iostream>
using namespace std;

class Tree
{
public:
	int* _arr;
	int _size;
	int _depth;

public:
	Tree(int depth, int size)
	{
		_depth = depth;
		_size = size;

		_arr = new int[_size] { -1 };
	}

	~Tree()
	{
		delete[] _arr;
	}

private:
	int ReturnLeftChildIndex(int index) { return 2 * index + 1; }

	int ReturnRightChildIndex(int index) { return 2 * index + 2; }

public:
	void Print()
	{
		// 1 2 4 8
		int sum = 1;
		int start = 0;
		for (int i = 0; i < _depth; i++)
		{
			for (int j = start; j < start + sum; j++)
			{
				if (j == start + sum - 1) cout << _arr[j];
				else cout << _arr[j] << " ";
			}

			if (i < _depth - 1) cout << '\n';
			start = start + sum;
			sum *= 2;
		}
	}

	void InorderTraverse(int index, int* InorderArr, int* inputIndex)
	{
		if (ReturnLeftChildIndex(index) < _size) InorderTraverse(ReturnLeftChildIndex(index), InorderArr, inputIndex);
		_arr[index] = InorderArr[*inputIndex];
		*inputIndex += 1;
		if (ReturnRightChildIndex(index) < _size) InorderTraverse(ReturnRightChildIndex(index), InorderArr, inputIndex);
	}
};

// ���� ���� Ʈ���̹Ƿ� �켱���� ť�� ����ؼ� Ǯ ���� �ִ�.
// �ƴϸ� ��� ������� �����ؼ� �Ϸķ� ����ϴ� ����� �����غ��� �͵� ����.

// ť�� �ְ� ����ϴ� ������� Ǯ�� �� --> �ڽ��� �ٽ� ť�� �ִ´�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	int size = 1;
	for (int i = 0; i < k; i++) size *= 2;
	size--;

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	int index = 0;
	Tree* tree = new Tree(k, size);
	tree->InorderTraverse(0, arr, &index);

	tree->Print();

	delete tree;
	delete[] arr;

	return 0;
}