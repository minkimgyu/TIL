#define _CRT_SECURE_NO_WARNINGS
// scanf 때문에 사용

#include <iostream>
using namespace std;

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	const int n = 9;
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]); // 한 줄씩 받아야하는 경우에는 scanf 사용
	}

	int max, index = -1;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			max = arr[i];
			index = i;
		}
		else
		{
			if (arr[i] > max)
			{
				max = arr[i];
				index = i;
			}
		}
	}

	cout << max << "\n";
	cout << index + 1 << "\n";

	return 0;
}