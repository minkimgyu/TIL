#pragma once

void BubbleSort(int* arr, int size)
{
	for (int i = size; i > 1; i--)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

// Stable: Yes
// In-place: Yes
// 버블 정렬의 가장 큰 장점: 간단함, 구현하기 쉬움, 추가 메모리 X

// BestCase (최선의 경우) Time Complexity: O(n^2)
// WorstCase(최악의 경우) Time Complexity: O(n^2)