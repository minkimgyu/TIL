#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int heap[maxSize];
int sz = 0;

int getChildIndex(int index, bool isLeft)
{
	if(isLeft) return 2 * index;
	else return 2 * index + 1;
}

int getParentIndex(int index)
{
	return index / 2;
}

void swap(int a, int b)
{
	int item = heap[a];
	heap[a] = heap[b];
	heap[b] = item;
}

void percolateUp(int index)
{
	if (index == 1) return;

	int parentIndex = getParentIndex(index);
	int parent = heap[parentIndex];
	int current = heap[index];

	if (current < parent) // �θ� �ڽĺ��� ū ���
	{
		swap(index, parentIndex);
		percolateUp(parentIndex);
	}
}

void percolateDown(int index)
{
	int leftIndex = getChildIndex(index, true);
	int rightIndex = getChildIndex(index, false);

	if (sz >= leftIndex) // ���� �ڽ��� �����ϴ� ���
	{
		if (sz >= rightIndex && heap[leftIndex] > heap[rightIndex]) // ������ �ڽ��� �����ϰ� ���� �ڽ��� ������ �ڽĺ��� ū ���
		{
			leftIndex = rightIndex;
		}

		if (heap[leftIndex] < heap[index]) // �θ� �ڽĺ��� ū ���
		{
			swap(leftIndex, index);
			percolateDown(leftIndex);
		}
	}
}

int top()
{
	if (sz == 0) return -1;
	return heap[1];
}

void push(int x)
{
	sz++;
	heap[sz] = x;
	percolateUp(sz);
}

void pop()
{
	if (sz == 0) return;

	swap(1, sz);
	sz--; // ������ ���� ����
	percolateDown(1); // percolate down ����
}

int main()
{
	push(35);
	push(55);
	push(15);
	push(8);
	push(32);

	for (int i = 0; i < 5; i++)
	{
		pop();
	}

	return 0;
}