#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, l;
	cin >> m >> n >> l;

	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + m);
	int killCount = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		if (y > l) continue;

		int start = 0;
		int end = m - 1;

		int xAmount = l - y;

		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (-xAmount + x <= arr[mid] && arr[mid] <= xAmount + x)
			{
				killCount++;
				break;
			}
			else if (arr[mid] < -xAmount + x)
			{
				start = mid + 1;
			}
			else if (xAmount + x < arr[mid])
			{
				end = mid - 1;
			}
		}
	}

	cout << killCount;
	return 0;
}