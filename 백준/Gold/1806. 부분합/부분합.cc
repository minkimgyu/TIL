#include <iostream>
using namespace std;

int n, s;

const int maxSize = 100000;
int arr[maxSize];

//  "이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중"
// 이 문제는 정렬하면 안 된다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = -1;
	int end = -1;

	int  sum = 0;
	int minLength = maxSize;
	int resultLength = 0;

	while (start < n)
	{
		if (sum < s && end < n - 1)
		{
			resultLength++;
			end++;
			sum += arr[end];
		}
		else 
		{
			resultLength--;
			start++;
			sum -= arr[start];
		}

		if (sum >= s && minLength > resultLength)
		{
			minLength = resultLength;
		}
	}

	if (minLength == maxSize)
	{
		cout << 0;
	}
	else
	{
		cout << minLength;
	}

	return 0;
}