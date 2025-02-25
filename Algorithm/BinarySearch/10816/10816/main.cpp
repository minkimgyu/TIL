#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 500000;
int arr[maxSize];

int lower_idx(int target, int len)
{
	int start, end, mid = 0;

	start = 0;
	end = len; // ����! ���̷� �Ҵ��������

	while (start < end) // start�� end�� ��ġ���� ���� ������ ������. != �� ������ �ȴ�.
	{
		mid = (start + end) / 2;

		if (arr[mid] >= target) // �Ķ��� ����
		{
			end = mid;
		}
		else // ��� ����
		{
			start = mid + 1;
		}
	}

	return start;
}

int upper_idx(int target, int len)
{
	int start, end, mid = 0;

	start = 0;
	end = len; // ����! ���̷� �Ҵ��������

	while (start < end) // start�� end�� ��ġ���� ���� ������ ������. != �� ������ �ȴ�.
	{
		mid = (start + end) / 2;

		if (arr[mid] > target) // �Ķ��� ����
		{
			end = mid;
		}
		else // ��� ����
		{
			start = mid + 1;
		}
	}

	return start;
}

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

	vector<int> results;

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int numToFind;
		cin >> numToFind;

		int* lowerIndex = lower_bound(arr, arr + n, numToFind);
		int* upperIndex = upper_bound(arr, arr + n, numToFind);

		results.push_back(upperIndex - lowerIndex);
	}

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i];
		if (i != results.size() - 1) cout << " ";
	}

	return 0;
}