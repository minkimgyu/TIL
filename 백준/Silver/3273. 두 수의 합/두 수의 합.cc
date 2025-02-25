#include <iostream>
#include <algorithm>
using namespace std;

int n;

const int arrSize = 100000;
int arr[arrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int sumResult;
	cin >> sumResult;

	int result = 0;

	sort(arr, arr + n);

	int firstIndex = 0;
	int endIndex = n - 1;

	while (firstIndex < endIndex)
	{
		int sum = arr[firstIndex] + arr[endIndex];
		if (sum < sumResult)
		{
			firstIndex++;
		}
		else if (sum > sumResult)
		{
			endIndex--;
		}
		else
		{
			result++;
			firstIndex++;
			endIndex--;
		}
	}

	cout << result;

	return 0;
}