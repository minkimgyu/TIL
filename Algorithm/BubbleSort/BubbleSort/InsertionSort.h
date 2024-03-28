#pragma once

void InsertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) // j가 0과 같거나 더 크고 arr[j]가 처음 선정한 key 값보다 큰 경우
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Stable: Yes --> 더 커야 위치를 바꾸기 때문에 순서가 유지된다.
// In-place: Yes
// 삽입 정렬의 가장 큰 장점: 시간 복잡도가 경우에 따라서 버블 정렬이랑 선택 정렬보다 낮을 수 있다.


// 이미 정렬이 되어있는 경우 --> 최선의 경우임
// BestCase (최선의 경우) Time Complexity: O(n)
// WorstCase(최악의 경우) Time Complexity: O(n^2)