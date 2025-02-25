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

		bool canFind = false;

		st = 0;
		en = n - 1;
		mid = (st + en) / 2;

		while (st <= en) // en이 st보다 커질 때까지 진행
		{
			if (arr[mid] > numToFind)
			{
				en = mid - 1;
				mid = (st + en) / 2;
			}
			else if (arr[mid] < numToFind)
			{
				st = mid + 1;
				mid = (st + en) / 2;
			}
			else
			{
				canFind = true;
				break;
			}
		}

		if (canFind == true) cout << 1;
		else cout << 0;

		if (i != m - 1) cout << '\n';
	}

	return 0;
}