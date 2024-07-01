#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 1;
	int end = arr[n - 1] - arr[0];
	int result = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int cnt = 1;
		int previous = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] - previous >= mid)
			{
				cnt++;
				previous = arr[i];
			}
		}

		if (cnt >= c)
		{
			result = max(result, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << result;

	return 0;
}