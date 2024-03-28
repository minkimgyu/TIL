#pragma once

int Partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int index = start;

	for (int i = start; i < end; i++)
	{
		if (arr[i] < pivot)
		{
			Swap(arr, index, i);
			index++;
		}
	}

	Swap(arr, index, end); // 피벗 값과 이보다 큰 첫번째 값을 서로 바꿔서 파티션 진행
	return index;
}

void QuickSort(int* arr, int start, int end)
{
	if (start >= end) return;

	int index = Partition(arr, start, end);
	QuickSort(arr, start, index - 1);
	QuickSort(arr, index + 1, end);
}

// Quick sort

// Partition이 성능을 좌우함

// 시간적 복잡도
// 
// 극도로 불균등한 리스트로 분할되는 경우 --> 이미 정렬되어 있는 경우, 같은 원소가 많은 경우
// 최악의 경우: O(n^2)
// 
// 거의 균등한 리스트로 분할되는 경우
// 최선의 경우: O(n * logn)

// Stable: No --> 피벗에 따라 스왑하기 때문에 유지되지 않을 수도 있음
// In-place: Yes