#include <iostream>
using namespace std;

const int maxSize = 100000;
long long int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, m;
	cin >> n >> m;

	long long int maxTime = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxTime = max(maxTime, arr[i]);
	}

	long long int left = 1;
	long long int right = maxTime * m;

	while (left <= right)
	{
		long long int mid = (left + right) / 2;

		long long int passCount = 0;
		for (int i = 0; i < n; i++)
		{
			passCount += mid / arr[i];
			if (passCount > m) break;
		}

		if (passCount >= m) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;

	return 0;
}