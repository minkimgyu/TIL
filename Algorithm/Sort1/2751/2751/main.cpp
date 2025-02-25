#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];
int tmp[maxSize];

void merge(int st, int en)
{
	int mid = (st + en) / 2;

	int lidx = st;
	int ridx = mid;

	for (int i = st; i < en; i++)
	{
		if (lidx >= mid)
		{
			tmp[i] = arr[ridx];
			ridx++;
		}
		else if (ridx >= en)
		{
			tmp[i] = arr[lidx];
			lidx++;
		}
		else
		{
			if (arr[lidx] <= arr[ridx])
			{
				tmp[i] = arr[lidx];
				lidx++;
			}
			else
			{
				tmp[i] = arr[ridx];
				ridx++;
			}
		}
	}

	for (int i = st; i < en; i++)
	{
		arr[i] = tmp[i];
	}
}

void mergeSort(int st, int en) // [st, en)
{
	if (en == st + 1) return; // 범위에 원소가 1개인 경우

	int mid = (st + en) / 2;
	mergeSort(st, mid);
	mergeSort(mid, en);
	merge(st, en);
}

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

	mergeSort(0, n);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1) cout << '\n';
	}

	return 0;
}