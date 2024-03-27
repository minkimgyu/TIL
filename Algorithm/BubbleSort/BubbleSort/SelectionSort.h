#pragma once

// Stable: No
// In-place: Yes
// 선택 정렬의 가장 큰 장점: 간단함, 구현하기 쉬움

// BesCase (최선의 경우) Time Complexity: O(n^2)
// WorstCase(최악의 경우) Time Complexity O(n^2)

int* SelectionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = arr[i]; // 최소값을 선택한다.
		int index = i;
		for (int j = i; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}

		// Swap
		int tmp = arr[i];
		arr[i] = min;
		arr[index] = tmp;
	}

	return arr;
}