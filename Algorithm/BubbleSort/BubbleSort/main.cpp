#include "Pch.h"

int main()
{
	const int size = 10;
	const int maxSize = 10;
	int* arr = ReturnRandomArr(size, maxSize);

	Print(arr, size);

	RadixSort(arr, size);

	Print(arr, size);

	delete[] arr;
	return 0;
}