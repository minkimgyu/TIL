#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n >> x;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < x)
		{
			if (i == n - 1) cout << arr[i];
			else cout << arr[i] << " ";
		}
	}

	delete []arr;

	return 0;
}