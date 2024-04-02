#include <iostream>
#include <algorithm>
using namespace std;

bool ACompare(int a, int b)
{
	return a > b;
}

bool BCompare(int a, int b)
{
	return a < b;
}

void Swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int Partition(int* arr, int start, int end, bool isUpOrder)
{
	int pivot = arr[end];
	int index = start;
	for (int i = start; i < end; i++)
	{
		bool condition;
		if (isUpOrder) condition = arr[i] < pivot;
		else condition = arr[i] > pivot;

		if (condition)
		{
			Swap(arr, index, i);
			index++;
		}
	}

	Swap(arr, index, end);
	return index;
}

void QuickSort(int* arr, int start, int end, bool isUpOrder)
{
	if (start >= end) return;

	int index = Partition(arr, start, end, isUpOrder);
	QuickSort(arr, start, index - 1, isUpOrder);
	QuickSort(arr, index + 1, end, isUpOrder);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* a = new int[n];
	int* b = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	//sort(a, a + n, ACompare);
	//sort(b, b + n, BCompare); 
	// --> 정렬된 B

	QuickSort(a, 0, n - 1, true);
	QuickSort(b, 0, n - 1, false);

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}

	cout << sum;

	return 0;
}