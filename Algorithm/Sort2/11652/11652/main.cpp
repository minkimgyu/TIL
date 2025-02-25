#include <iostream>
#include <algorithm>
using namespace std;

int currentCount = 0;
long long currentNum = 0;
long long int result = 0;
int maxCount = 0;

const int maxSize = 100000 + 5;
long long int arr[maxSize];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	result = arr[0];
	currentNum = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] != currentNum)
		{
			if (maxCount < currentCount)
			{
				maxCount = currentCount;
				result = currentNum;
			}

			currentNum = arr[i];
			currentCount = 0;
			currentCount++;
		}
		else
		{
			currentCount++;
		}
	}

	// 마지막 원소가 가장 많은 경우 업데이트 필요함
	if (maxCount < currentCount)
	{
		maxCount = currentCount;
		result = currentNum;
	}

	cout << result;
	return 0;
}