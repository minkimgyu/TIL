#include <iostream>
using namespace std;

int n;
const int arrSize = 11;
int arr[arrSize];

int main()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < arrSize; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		cout << arr[item];
		if(i != n - 1) cout << '\n';
	}

	return 0;
}