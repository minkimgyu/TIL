#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000 + 5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 1000000 + 5; j++) arr[j] = 0;

		int n;
		cin >> n;
		
		for (int j = 0; j < n; j++) cin >> arr[j];

		sort(arr, arr + n);

		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;

			bool canFind = binary_search(arr, arr + n, num);
			if (canFind == true) cout << 1;
			else cout << 0;
			cout << '\n';
		}
	}

	return 0;
}