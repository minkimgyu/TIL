#include <iostream>
#include <algorithm>

using namespace std;

const int arrSize = 100000;
int arr[100000];

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	// �������� ���� ���� �� * ������ ����

	for (int i = 0; i < n; i++)
	{
		int weight = arr[i] * (i + 1);
		if (result < weight) result = weight;
	}

	cout << result;
	return 0;
}