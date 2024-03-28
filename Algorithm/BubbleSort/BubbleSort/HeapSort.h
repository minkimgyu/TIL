#pragma once

int ReturnParentIndex(int index) { return (int)((index - 1) / 2); }

int ReturnLeftChildIndex(int index) { return 2 * index + 1; }

int ReturnRightChildIndex(int index) { return 2 * index + 2; }

// MaxHeap의 경우
void PercolateDown(int* arr, int size, int startIndex)
{
	int childIndex = ReturnLeftChildIndex(startIndex);
	int rightIndex = ReturnRightChildIndex(startIndex);

	if (rightIndex < size && arr[childIndex] < arr[rightIndex]) childIndex = rightIndex;

	if (childIndex < size - 1 && arr[childIndex] > arr[startIndex])
	{
		Swap(arr, startIndex, childIndex);
		PercolateDown(arr, size, childIndex);
	}
}

void BuildHeap(int* arr, int size)
{
	int maxIndex = ReturnParentIndex(size - 1);
	for (int i = maxIndex; i >= 0; i--)
	{
		PercolateDown(arr, size, i);
	}
}

void HeapSort(int* arr, int size)
{
	BuildHeap(arr, size);
	int maxIndex = size - 1;

	for (int i = 0; i < size; i++)
	{
		Swap(arr, 0, maxIndex - i);
		PercolateDown(arr, size - i, 0);
	}
}

// Heap sort

// 시간적 복잡도
// 
// O(n * logn)
// --> n + n * logn
// --> n(logn + 1)
// --> n(logn)
// 
// 정렬을 위한 추가적인 메모리가 필요하지 않다. (제자리 정렬 가능)
// 
// 최선, 평균, 최악의 경우의 모두 heapify 과정이 필요하기 때문에 nlogn 을 보장한다.
// 
// 데이터의 순서를 보장하지 못하는 불안정(unstable)정렬이다.
// 
// 힙정렬과 퀵정렬을 비교해보면 똑같은 nlogn 이지만 컴퓨터의 하드웨어 구조상 퀵정렬이 실제로는 더 빠르다고 한다.
// 이유는 퀵 정렬의 경우는 대개 원소들끼리 근접한 메모리 영역에 붙어 있는 배열을 사용하기 때문에 일반적으로 캐시 친화적이지만
// 힙정렬의 원소들은 좀 더 흩어져 있는 경우가 많아서 캐시 친화도가 떨어지는 문제가 있고
// 힙정렬은 일반적으로 포인터 연산을 많이 사용하기 때문에 거기에 걸리는 오버헤드도 무시할 수는 없는 수준이기 때문이다.
// 
// Stable: No --> PercolateDown에 의해 스왑될 수 있음
// In-place: Yes --> 추가 메모리 사용 안 함