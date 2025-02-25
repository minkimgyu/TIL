#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 10000;
long long  arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + k);

	// 최소 1cm씩 자를 수 있다.
	// 최대 가장 작은 랜선 길이만큼 자를 수 있다. --> K ≦ N이기 때문

	long long int start, end, mid;

	start = 1; // 최소 1cm

	end = 1; // 최대 2^31 - 1
	for (int i = 1; i <= 31; i++)
	{
		end *= 2;
	}
	end -= 1;

	// 1, 2, 3, 4, 5, n, 8, 9, 12, 15, 20

	while (start < end)
	{
		mid = (start + end + 1) / 2;

		int lenCount = 0;
		for (int i = 0; i < k; i++)
		{
			lenCount += (arr[i] / mid);
		}

		if (lenCount >= n) // 나오는 랜선 개수가 n보다 같거나 크다면
		{
			start = mid; // 길이를 늘린다.
		}
		else // 작다면
		{
			end = mid - 1; // -1을 하는 이유는 개수가 같거나 클수는 있지만 작을 수는 없기 때문이다.
		}
	}

	cout << start;
	return 0;
}