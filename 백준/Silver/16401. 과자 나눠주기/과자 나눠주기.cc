#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int left = 1;
	int right = 1000000000;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		int giveCount = 0;
		for (int i = 0; i < n; i++)
		{
			giveCount += arr[i] / mid;
		}

		if (giveCount < m) right = mid - 1;
		else left = mid + 1;
	}

	cout << right;

	return 0;
}