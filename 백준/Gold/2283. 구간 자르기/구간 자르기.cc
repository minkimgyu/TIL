#include <iostream>
using namespace std;

int n;
long long int k;

const int maxSize = 1000 + 5;
pair<int, int> arr[maxSize];

const int maxArrSize = 1000000 + 5;
long long int sumArr[maxArrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	int maxIndex = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;

		sumArr[arr[i].first] += 1;
		sumArr[arr[i].second] -= 1;

		maxIndex = max(maxIndex, arr[i].second);
	}

	// 차분 배열로 실연산값 구하기
	for (int i = 1; i <= maxIndex; i++)
	{
		sumArr[i] = sumArr[i] + sumArr[i - 1];
	}

	int firstItem = sumArr[0];

	// 누적합 구하기
	for (int i = 1; i <= maxIndex; i++)
	{
		sumArr[i] = sumArr[i] + sumArr[i - 1];
	}

	for (int i = maxIndex + 1; i > 0; i--)
	{
		sumArr[i] = sumArr[i - 1];
	}
	sumArr[0] = 0;

	int minLeft = 0;
	int minRight = 1;
	long long int result = 0;
	bool nowClear = false;

	// 찾으면 바로 리턴
	for (int left = 0; left <= maxIndex; left++)
	{
		while (sumArr[minRight] - sumArr[left] <= k)
		{
			result = sumArr[minRight] - sumArr[left];
			if (result == k) // 찾은 경우
			{
				minLeft = left;
				nowClear = true;
				break;
			}
			minRight++;
		}

		if (nowClear == true) break;
	}

	if (nowClear == false) cout << "0 0";
	else cout << minLeft << " " << minRight;
	
	return 0;
}