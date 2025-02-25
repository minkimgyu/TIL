#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 10000;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	// {a, b}
	// {b, a}
	// �̷� ������ �ߺ��Ǵ� �������� ������ �ȵ�
	// ���� �̱⸦ Ȱ���ؾ� �Ѵ�.

	long long int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = arr[i] + arr[j];

			int* start = lower_bound(arr + j + 1, arr + n, -sum); // arr ���� ��ġ���� j + 1��ŭ ���������
			int* end = upper_bound(arr + j + 1, arr + n, -sum);

			result += end - start;
		}
	}

	cout << result;
	return 0;
}