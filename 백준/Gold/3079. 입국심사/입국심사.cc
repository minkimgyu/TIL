#include <iostream>
using namespace std;

const int maxSize = 100000;
unsigned long long int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long int n, m;
	cin >> n >> m;

	unsigned long long int maxTime = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxTime = max(maxTime, arr[i]);
	}

	unsigned long long int left = 1;
	unsigned long long int right = maxTime * m;

	while (left <= right)
	{
		unsigned long long int mid = (left + right) / 2;

		unsigned long long int passCount = 0;
		for (int i = 0; i < n; i++)
		{
			passCount += mid / arr[i];
		}

		if (passCount >= m) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;

	return 0;
}