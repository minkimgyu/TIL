#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		if (i * 2 <= 1000000 && (arr[i * 2] == 0 || min(arr[i * 2], arr[i] + 1) == arr[i] + 1))
		{
			arr[i * 2] = arr[i] + 1;
		}

		if (i * 3 <= 1000000 && (arr[i * 3] == 0 || min(arr[i * 3], arr[i] + 1) == arr[i] + 1))
		{
			arr[i * 3] = arr[i] + 1;
		}

		if (i + 1 <= 1000000 && (arr[i + 1] == 0 || min(arr[i + 1], arr[i] + 1) == arr[i] + 1))
		{
			arr[i + 1] = arr[i] + 1;
		}
	}

	cout << arr[n];

	return 0;
}