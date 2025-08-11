#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int nASize = 500000 + 5;
int arr[nASize];
bool chk[nASize];

int nA, nB;

void binary_search(int num)
{
	int start = 0;
	int end = nA - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		// 0	(num1)	arr[mid]	(num2)	nA - 1
		if (arr[mid] > num) end = mid - 1;
		else if (arr[mid] < num) start = mid + 1;
		else
		{
			chk[mid] = false; // 찾은 경우
			break;
		}
	}
}

vector<int> results;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> nA >> nB;

	for (int i = 0; i < nA; i++)
	{
		cin >> arr[i];
		chk[i] = true;
	}

	sort(arr, arr + nA);

	for (int i = 0; i < nB; i++)
	{
		int bItem;
		cin >> bItem;

		binary_search(bItem);
	}

	int totalCount = 0;
	for (int i = 0; i < nA; i++)
	{
		if (chk[i] == true) totalCount++;
	}

	cout << totalCount;

	if (totalCount != 0)
	{
		cout << '\n';
		for (int i = 0; i < nA; i++)
		{
			if (chk[i] == true)
			{
				cout << arr[i];
				if (i != nA - 1) cout << " ";
			}
		}
	}
	
	return 0;
}