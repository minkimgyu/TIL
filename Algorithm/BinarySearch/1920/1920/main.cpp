#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100000;
int arr[maxSize];

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

	int st, en, mid;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int numToFind;
		cin >> numToFind;

		bool canFind = binary_search(arr, arr + n, numToFind);
		if (canFind == true) cout << 1;
		else cout << 0;

		if (i != m - 1) cout << '\n';
	}

	return 0;
}