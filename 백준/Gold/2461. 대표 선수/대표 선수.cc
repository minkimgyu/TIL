#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 1000 + 5;
pair<int, int> arr[maxSize * maxSize]; // num, type
int checkArr[maxSize];

int n, m;

bool containAllClass()
{
	for (int i = 0; i < n; i++)
	{
		if (checkArr[i] == 0) return false; // 비어있다면
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int start = i * m;
		for (int j = start; j < start + m; j++)
		{
			int item;
			cin >> item;
			arr[j] = { item, i };
		}
	}
	 
	int totalSize = n * m;
	sort(arr, arr + totalSize);

	int right = 0;
	checkArr[arr[right].second] += 1;

	int result = 1000000005;

	for (int left = 0; left < totalSize; left++)
	{
		if(left >= 1) checkArr[arr[left - 1].second] -= 1;

		while (containAllClass() == false && right < (totalSize - 1))
		{
			right++;
			checkArr[arr[right].second] += 1;
		}

		if (containAllClass() == true)
		{
			result = min(result, arr[right].first - arr[left].first);
		}
	}

	cout << result;
	return 0;
}