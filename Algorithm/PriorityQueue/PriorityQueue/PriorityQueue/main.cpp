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

	if (current < parent) // 부모가 자식보다 큰 경우
	{
		swap(index, parentIndex);
		percolateUp(parentIndex);
	}
}

void percolateDown(int index)
{
	int leftIndex = getChildIndex(index, true);
	int rightIndex = getChildIndex(index, false);

	if (sz >= leftIndex) // 왼쪽 자식이 존재하는 경우
	{
		if (sz >= rightIndex && heap[leftIndex] > heap[rightIndex]) // 오른쪽 자식이 존재하고 왼쪽 자식이 오른쪽 자식보다 큰 경우
		{
			leftIndex = rightIndex;
		}

		if (heap[leftIndex] < heap[index]) // 부모가 자식보다 큰 경우
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
	sz--; // 마지막 원소 제거
	percolateDown(1); // percolate down 적용
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