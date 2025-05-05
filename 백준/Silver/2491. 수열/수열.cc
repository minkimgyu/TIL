#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

int increaseDp[maxSize];
int decreaseDp[maxSize];

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

	int maxLength = 0;

	fill(increaseDp, increaseDp + n, 1);
	fill(decreaseDp, decreaseDp + n, 1);

	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= arr[i - 1]) // 뒤 값이 더 크거나 같은 경우
		{
			increaseDp[i] = increaseDp[i - 1] + 1;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i] <= arr[i - 1]) // 앞 값이 더 크거나 같은 경우
		{
			decreaseDp[i] = decreaseDp[i - 1] + 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		maxLength = max(maxLength, increaseDp[i]);
	}

	for (int i = 1; i < n; i++)
	{
		maxLength = max(maxLength, decreaseDp[i]);
	}

	cout << maxLength;
	return 0;
}