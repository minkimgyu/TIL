#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 20000 + 5;
int arrA[maxSize];
int arrB[maxSize];

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;

		for (int j = 0; j < n; j++)
		{
			cin >> arrA[j];
		}

		for (int j = 0; j < m; j++)
		{
			cin >> arrB[j];
		}

		sort(arrB, arrB + m);
		int result = 0;

		for (int k = 0; k < n; k++)
		{
			int item = arrA[k];
			result += lower_bound(arrB, arrB + m, item) - arrB;
		}

		cout << result;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}