#include <iostream>
#include <algorithm>
using namespace std;

const int n = 8;
int arr[n] = { 6, -8, 1, 12, 8, 3, 7, -7 };
int tmp[n]; // 정렬된 값을 임시로 저장할 변수

void merge(int st, int en)
{
	int mid = (st + en) / 2; // st는 0 en은 10

	int lidx = st;
	int ridx = mid;

	for (int i = st; i < en; i++)
	{
		if (ridx == en)
		{
			tmp[i] = arr[lidx];
			lidx++;
		}
		else if (lidx == mid)
		{
			tmp[i] = arr[ridx];
			ridx++;
		}
		else
		{
			if (arr[lidx] <= arr[ridx])
			{
				tmp[i] = arr[lidx];
				lidx++;
			}
			else
			{
				tmp[i] = arr[ridx];
				ridx++;
			}
		}
	}

	for (int i = st; i < en; i++)
	{
		arr[i] = tmp[i];
	}
}

void mergeSort(int st, int en) // st는 닫힌 구간, en은 열린 구간 [st, en) 
{
	if (st + 1 == en) return; // st와 en 범위 안에 수가 1개인 경우

	int mid = (st + en) / 2;
	mergeSort(st, mid);
	mergeSort(mid, en);
	merge(st, en);
}

void bubbleSort()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectionSort()
{
	for (int i = n - 1; i > 0; i--)
	{
		int mxidx = 0;
		for (int j = 1; j <= i; j++)
		{
			if (arr[mxidx] < arr[j]) mxidx = j;
		}

		swap(arr[mxidx], arr[i]);
	}

	/*for (int i = n - 1; i > 0; i--)
	{
		swap(*max_element(arr, arr + i + 1), arr[i]);
	}*/
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

int partition(int st, int en)
{
	int pivot = arr[st];
	int l = st + 1;
	int r = en - 1;

	while (1)
	{
		while (arr[l] <= pivot) l++;
		while (arr[r] > pivot) r--;

		if (r < l) break;
		swap(arr[l], arr[r]);
	}

	swap(arr[st], arr[r]);
	return r;
}

void quickSort(int st, int en)
{
	if (st + 1 >= en) return; // 현재 보는 길이가 1 이하인 경우
	int mid = partition(st, en);

	quickSort(st, mid);
	quickSort(mid + 1, en);
}

int main()
{
	quickSort(0, 8);
	print();
	return 0;
}