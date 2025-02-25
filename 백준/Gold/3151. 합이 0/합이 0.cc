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
	// 이런 식으로 중복되는 선택지가 있으면 안됨
	// 조합 뽑기를 활용해야 한다.

	long long int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = arr[i] + arr[j];

			int* start = lower_bound(arr + j + 1, arr + n, -sum); // arr 시작 위치에서 j + 1만큼 더해줘야함
			int* end = upper_bound(arr + j + 1, arr + n, -sum);

			result += end - start;
		}
	}

	cout << result;
	return 0;
}