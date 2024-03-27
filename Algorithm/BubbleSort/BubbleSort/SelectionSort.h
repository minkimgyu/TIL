#pragma once

// Stable: No
// In-place: Yes
// ���� ������ ���� ū ����: ������, �����ϱ� ����

// BesCase (�ּ��� ���) Time Complexity: O(n^2)
// WorstCase(�־��� ���) Time Complexity O(n^2)

int* SelectionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = arr[i]; // �ּҰ��� �����Ѵ�.
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