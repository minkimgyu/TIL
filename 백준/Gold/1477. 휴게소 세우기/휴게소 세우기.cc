#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, l;
	cin >> n >> m >> l;

	vector<int> arr;
	arr.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
	}
	arr.push_back(l);

	int arrSize = arr.size();

	sort(arr.begin(), arr.end());

	int start = 1;
	int end = l - 1;
	int result = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int cnt = 0;
		for (int i = 1; i < arrSize; i++)
		{
			int len = arr[i] - arr[i - 1];

			cnt += len / mid;
			if (len % mid == 0) cnt -= 1; // 이미 휴게소가 설치된 곳에 다시 설치할 수 없음
		}

		if (cnt > m) // 심을 수 있는 개수보다 더 많은 경우 -> 길이 늘리기
		{
			start = mid + 1;
		}
		else // 더 작은 경우 -> 길이 줄이기
		{
			result = mid;
			end = mid - 1;
		}
	}

	cout << result;
	return 0;
}