#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;

	long long int left = 1;
	long long int right;

	long long int* arr = new long long int[k];
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		if (i == 0) right = arr[i];
		else { if (arr[i] > right) right = arr[i]; }
	}

	while (left <= right)
	{
		long long int mid = (long long int)((left + right) / 2);
		long long int sum = 0;
		for (int i = 0; i < k; i++)
		{
			sum += (long long int)(arr[i] / mid);
		}

		// n = 11
		// n이 sum보다 크다는 소리는 랜선 1개당 길이가 너무 길다는 소리임
		if (n > sum)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << right;

	return 0;
}