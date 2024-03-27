#pragma once

// Stable: Yes
// In-place: Yes
// ���� ������ ���� ū ����: ������, �����ϱ� ����, �߰� �޸� X

// BesCase (�ּ��� ���) Time Complexity: O(n^2)
// WorstCase(�־��� ���) Time Complexity O(n^2)

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