#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 5000 + 5;
long long int arr[maxSize];

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

	long long int minValue = 3000000000 + 5;
	long long int storedA = 0;
	long long int storedB = 0;
	long long int storedC = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 2; j < n; j++)
		{
			long long int a = arr[i];
			long long int b = arr[j];

			int left = i + 1;
			int right = j - 1;

			while (left <= right)
			{
				int mid = (left + right) / 2;
				long long int sum = a + b + arr[mid];

				if (minValue > abs(sum))
				{
					storedA = a;
					storedB = b;
					storedC = arr[mid];

					minValue = abs(sum);
				}

				if (sum > 0)
				{
					right = mid - 1;
				}
				else if(sum < 0)
				{
					left = mid + 1;
				}
				else // 0인 경우
				{
					cout << storedA << " " << storedC << " " << storedB;
					return 0;
				}
			}
		}
	}

	cout << storedA << " " << storedC << " " << storedB;
	return 0;
}