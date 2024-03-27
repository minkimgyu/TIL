#include "Pch.h"

#include "BubbleSort.h"
#include "SelectionSort.h"

int main()
{
	const int size = 6;
	int* arr = ReturnRandomArr(size, 10);

	Print(arr, size);

	SelectionSort(arr, size);

	Print(arr, size);

	delete[] arr;
	return 0;
}