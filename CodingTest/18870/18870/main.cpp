#include <iostream>
#include <unordered_map>
using namespace std;

void Swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int Partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int i = start;
	for (int j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			Swap(arr, i, j);
			i++;
		}
	}

	Swap(arr, i, end);
	return i;
}

void QuickSort(int* arr, int start, int end)
{
	if (start >= end) return;

	int index = Partition(arr, start, end);
	QuickSort(arr, start, index - 1);
	QuickSort(arr, index + 1, end);
}

// Hesh를 사용해서 푸는 문제
// 시간 복잡도 때문에 한가지 값만 저장하는 방식으로 푸는게 합리적임

int main()
{
	int n;
	cin >> n;

	int* orderedArr = new int[n];
	int* arr = new int[n];

	unordered_map<int, int> uM;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;

		arr[i] = tmp;

		// 값이 존재한다면 continue
		if (uM.find(tmp) != uM.end()) continue;

		orderedArr[cnt] = tmp;
		uM[tmp] = 0;
		cnt++;
	}

	QuickSort(orderedArr, 0, cnt - 1);
	for (int i = 0; i <= cnt; i++)
	{
		uM[orderedArr[i]] += i; // i
	}

	for (int i = 0; i < n; i++)
	{
		cout << uM[arr[i]] << " ";
	}

	return 0;
}