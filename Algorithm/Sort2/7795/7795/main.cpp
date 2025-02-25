#include <iostream>
#include <algorithm>
using namespace std;

int arrA[20000];
int arrB[20000];

bool compare(int a, int b)
{
	return a > b;
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
		int n, m;
		cin >> n >> m;

		for (int j = 0; j < n; j++)
		{
			cin >> arrA[j];
		}

		for (int j = 0; j < m; j++)
		{
			cin >> arrB[j];
		}

		sort(arrA, arrA + n);
		sort(arrB, arrB + m);

		int aIndex = 0;
		int bIndex = 0;
		int result = 0;

		for (int i = 0; i < n; i++)
		{
			int* p = lower_bound(arrB, arrB + m, arrA[i]);
			result += p - arrB;
		}

		cout << result;
		if (i != t - 1) cout << '\n';

		fill(arrA, arrA + n, 0);
		fill(arrB, arrB + m, 0);
	}

	return 0;
}