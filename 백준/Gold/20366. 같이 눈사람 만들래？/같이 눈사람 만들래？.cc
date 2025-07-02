#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 600 + 5;
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

	int result = 2000000005;

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (j - i < 3) continue;

			int sum1 = arr[j] + arr[i];

			int left = i + 1;
			int right = j - 1;

			while (left < right)
			{
				int sum2 = arr[left] + arr[right];

				result = min(result, abs(sum1 - sum2));
				if (sum1 == arr[left] + arr[right])
				{
					left++;
					right--;
				}
				else if (sum1 < arr[left] + arr[right])
				{
					right--;
				}
				else if (sum1 > arr[left] + arr[right])
				{
					left++;
				}
			}
		}
	}
	
	cout << result;
	return 0;
}