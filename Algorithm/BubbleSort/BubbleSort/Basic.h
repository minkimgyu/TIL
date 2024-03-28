#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int* ReturnRandomArr(int size, int maxSize)
{
	srand((unsigned int)time(NULL));

	int* arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = rand() % maxSize;

	return arr;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1) cout << arr[i] << '\n';
		else cout << arr[i] << " ";
	}
}