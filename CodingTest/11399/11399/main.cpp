#include <iostream>
using namespace std;

void quickSort(int* data, int start, int end) {
    if (start >= end) return; // ���Ұ� 1���� ��� �״�� ����

    int pivot = start; // �Ǻ��� ù ��° ����
    int i = start + 1, j = end, temp;

    while (i <= j) { // ������ ������ �ݺ� 
        while (i <= end && data[i] <= data[pivot]) i++; // �Ǻ� ������ ū ���� ���� ������

        while (j > start && data[j] >= data[pivot]) j--; // �Ǻ� ������ ���� ���� ���� ������

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

// ������ ���������� --> �̿տ� ���� �˰��� �ѹ��� ���ƺ���

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

