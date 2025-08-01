#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 10000 + 5;
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

	int m;
	cin >> m;

	sort(arr, arr + n);

	int left = 1;
	int right = arr[n - 1];

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int currentBuget = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < mid) currentBuget += arr[i];
			else currentBuget += mid;
		}

		if (currentBuget > m) right = mid - 1;
		else left = mid + 1;
	}

	cout << right;

	return 0;
}