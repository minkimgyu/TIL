#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 500000;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int numToFind;
		cin >> numToFind;

		//int start, end, mid;

		//start = 0;
		//end = n - 1;
		bool canFind = false;

		/*while (start <= end)
		{
			mid = (start + end) / 2;
			if (arr[mid] > numToFind)
			{
				end = mid - 1;
			}
			else if (arr[mid] < numToFind)
			{
				start = mid + 1;
			}
			else
			{
				canFind = true;
				break;
			}
		}*/

		canFind = binary_search(arr, arr + n, numToFind);

		if (canFind == true) cout << 1;
		else cout << 0;

		if (i != m - 1) cout << " ";
	}

	return 0;
}