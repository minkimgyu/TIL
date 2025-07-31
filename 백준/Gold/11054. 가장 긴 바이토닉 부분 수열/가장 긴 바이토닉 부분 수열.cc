#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 1000 + 5;
int arr[maxSize];
int minusArr[maxSize];

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
		minusArr[i] = -arr[i]; // 음수로 설정해주기
	}

	int maxArrSize = 0;

	for (int k = 0; k < n; k++)
	{
		int midIdx = k;

		vector<int> plusVec;

		for (int i = 0; i <= k; i++)
		{
			int idx = lower_bound(plusVec.begin(), plusVec.end(), arr[i]) - plusVec.begin();
			if (plusVec.size() == idx)
			{
				plusVec.push_back(arr[i]);
			}
			else
			{
				plusVec[idx] = arr[i];
			}
		}

		vector<int> minusVec;

		for (int i = k; i < n; i++)
		{
			int idx = lower_bound(minusVec.begin(), minusVec.end(), minusArr[i]) - minusVec.begin();
			if (minusVec.size() == idx)
			{
				minusVec.push_back(minusArr[i]);
			}
			else
			{
				minusVec[idx] = minusArr[i];
			}
		}

		int currentSize = plusVec.size() + minusVec.size() - 1;
		maxArrSize = max(maxArrSize, currentSize);
	}

	cout << maxArrSize;

	return 0;
}