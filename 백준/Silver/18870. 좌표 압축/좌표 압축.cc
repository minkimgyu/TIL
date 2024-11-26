#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxSize = 1000000;
int arr[maxSize];
int inputArr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int inputNum;
		cin >> inputNum;

		arr[i] = inputNum;
		inputArr[i] = inputNum;
	}

	sort(arr, arr + n);

	vector<int> vec;

	int beforeNum = arr[0];
	vec.push_back(beforeNum);

	for (int i = 1; i < n; i++)
	{
		if (beforeNum == arr[i])
		{
			continue;
		}
		else
		{
			beforeNum = arr[i];
			vec.push_back(arr[i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		int start, end, mid, target;

		target = inputArr[i];
		start = 0;
		end = vec.size();

		while (start < end)
		{
			mid = (start + end) / 2;
			if (vec[mid] >= target)
			{
				end = mid;
			}
			else
			{
				start = mid + 1;
			}
		}

		// start가 인덱스
		cout << start;
		if (i != n - 1) cout << " ";
	}

	return 0;
}