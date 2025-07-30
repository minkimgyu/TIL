#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int total = 0;
	int result = -100 * 100000 - 5;
	int right = -1;

	for (int left = 0; left < n; left++)
	{
		while (right < n - 1 && right - left < k - 1)
		{
			right++;
			total += arr[right];
		}

		if (right - left == k - 1)
		{
			result = max(result, total);
		}

		total -= arr[left];
	}

	cout << result;
	return 0;
}