#include <iostream>
using namespace std;

void quickSort(int* data, int start, int end) {
    if (start >= end) return; // 원소가 1개인 경우 그대로 리턴

    int pivot = start; // 피봇은 첫 번째 원소
    int i = start + 1, j = end, temp;

    while (i <= j) { // 엇갈릴 때까지 반복 
        while (i <= end && data[i] <= data[pivot]) i++; // 피봇 값보다 큰 값을 만날 때까지

        while (j > start && data[j] >= data[pivot]) j--; // 피봇 값보다 작은 값을 만날 떄까지

        if (i > j) {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);

}

// 퀵정렬 공부해주자 --> 이왕에 정렬 알고리즘 한바쿼 돌아보기

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size = 1000;

	int n;
	cin >> n;

	int arr[size];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

    quickSort(arr, 0, n - 1);

	int sum = 0;
    int beforeSum = 0;

	for (int i = 0; i < n; i++)
	{
        beforeSum += arr[i];
        sum += beforeSum;
	}

	cout << sum;
	return 0;
}

