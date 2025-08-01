#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int left = 0;
	int right = arr[n - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;

		// currentHeight는 높이 기준이 됨
		long long int currentHeight = 0;
		for (int i = 0; i < n; i++)
		{
			int diff = arr[i] - mid;
			if (diff <= 0) continue;

			currentHeight += diff;
		}

		if (currentHeight >= m) // 오른쪽 선택 -> 만약 같아도 더 큰 값을 잡아야하므로 >= 부등호
		{
			left = mid + 1;
		}
		else if (currentHeight < m) // 왼쪽 선택
		{
			right = mid - 1;
		}
	}

	cout << right;
	return 0;
}