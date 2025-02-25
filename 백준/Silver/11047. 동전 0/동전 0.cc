#include <iostream>
using namespace std;

const int maxSize = 10 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int result = 0;

	for (int i = n - 1; i > -1; i--)
	{
		if (k < arr[i]) continue;

		int modCount = k / arr[i];
		int modLeft = k % arr[i];

		k = modLeft;
		result += modCount;
	}

	cout << result;

	return 0;
}