#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];

	int min, max;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			min = arr[i];
			max = arr[i];
		}
		else
		{
			if (arr[i] < min) min = arr[i];
			if (arr[i] > max) max = arr[i];
		}
	}

	cout << min << " " << max;

	delete[] arr;

	return 0;
}