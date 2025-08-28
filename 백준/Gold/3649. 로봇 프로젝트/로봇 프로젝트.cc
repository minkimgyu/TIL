#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];

int x;
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (cin >> x)
	{
		x *= 10000000;

		cin >> n;

		//for (int i = 0; i < maxSize; i++) arr[i] = 0; // 초기화

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		sort(arr, arr + n);

		int left = 0;
		int right = n - 1;

		bool canClear = false;

		while (left < right)
		{
			int sum = arr[left] + arr[right];

			if (sum < x)
			{
				left++;
			}
			else if (sum > x)
			{
				right--;
			}
			else
			{
				canClear = true;
				break;
			}
		}

		if (canClear == true)
		{
			cout << "yes " << arr[left] << " " << arr[right] << '\n';
		}
		else
		{
			cout << "danger" << '\n';
		}
	}


	return 0;
}