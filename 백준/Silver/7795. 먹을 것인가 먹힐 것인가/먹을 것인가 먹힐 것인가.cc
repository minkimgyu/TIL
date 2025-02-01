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

		sort(arrA, arrA + n, compare);
		sort(arrB, arrB + m, compare);

		int aIndex = 0;
		int bIndex = 0;
		int result = 0;

		while (1)
		{
			if (aIndex == n || bIndex == m)
			{
				break;
			}
			else
			{
				if (arrA[aIndex] > arrB[bIndex])
				{
					result += m - bIndex;
					aIndex++;
				}
				else
				{
					bIndex++;
				}
			}
		}

		cout << result;
		if (i != t - 1) cout << '\n';

		fill(arrA, arrA + n, 0);
		fill(arrB, arrB + m, 0);
	}

	return 0;
}