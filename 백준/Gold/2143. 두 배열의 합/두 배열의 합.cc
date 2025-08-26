#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;

int arrA[1000 + 5];
int arrB[1000 + 5];

vector<int> prefixA, prefixB;

int lowerBound(int item)
{
	int left = 0;
	int right = prefixB.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (prefixB[mid] >= item)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return left;
}

int upperBound(int item)
{
	int left = 0;
	int right = prefixB.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (prefixB[mid] > item)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return left;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arrA[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arrB[i];
	}

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arrA[j];
			prefixA.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += arrB[j];
			prefixB.push_back(sum);
		}
	}

	sort(prefixB.begin(), prefixB.end());

	long long int result = 0;

	for (int i = 0; i < prefixA.size(); i++)
	{
		int numToFind = t - prefixA[i];
		long long upper = upperBound(numToFind);
		long long lower = lowerBound(numToFind);

		result += upper - lower;
	}

	cout << result;
	return 0;
}