#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000 + 5];
int n;

bool binarySearch(int num)
{
	int s = 0;
	int e = n - 1;

	while (s <= e)
	{
		int m = (s + e) / 2;
		if (arr[m] > num) e = m - 1;
		else if (arr[m] < num) s = m + 1;
		else // 같을 경우
		{
			return true;
		}
	}

	return false;
}

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

		
		cin >> n;
		
		for (int j = 0; j < n; j++) cin >> arr[j];

		sort(arr, arr + n);

		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;

			bool canFind = binarySearch(num);
			if (canFind == true) cout << 1;
			else cout << 0;
			cout << '\n';
		}
	}

	return 0;
}