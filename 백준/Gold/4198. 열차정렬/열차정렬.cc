#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 2000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int maxResult = 0;

	for (int k = 0; k < n; k++)
	{
		vector<int> lis;
		vector<int> lds;

		for (int i = k; i < n; i++)
		{
			if (lis.empty() == true)
			{
				lis.push_back(arr[i]);
			}
			else
			{
				if (arr[k] > arr[i]) continue; // 첫 값이 더 크면 건너뛰기

				int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin(); // 기본적으로 less - 오름차순 처리되어있음

				if (index == lis.size())
				{
					lis.push_back(arr[i]);
				}
				else
				{
					lis[index] = arr[i];
				}
			}
		}

		for (int i = k; i < n; i++)
		{
			if (lds.empty() == true)
			{
				lds.push_back(arr[i]);
			}
			else
			{
				if (arr[k] < arr[i]) continue; // 첫 값이 더 작으면 건너뛰기

				int index = lower_bound(lds.begin(), lds.end(), arr[i], greater<int>()) - lds.begin(); // 내림차순

				if (index == lds.size())
				{
					lds.push_back(arr[i]);
				}
				else
				{
					lds[index] = arr[i];
				}
			}
		}

		int result = lis.size() + lds.size() - 1;
		maxResult = max(maxResult, result);
	}
	
	cout << maxResult;
	return 0;
}
