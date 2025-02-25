#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

const int maxSize = 100000;
int arr[maxSize];

const int maxM = 2000000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 0;
	int end = 0;

	int result = 0;
	int subtractResult = maxM;
	int answer = 0;

	while (start < n - 1)
	{
		if (result < m && end < n - 1) // 결과 값이 원하는 값보다 작거나 end가 n - 1보다 작은 경우
		{
			end++;
		}
		else // 나머지 경우
		{
			start++;
		}

		result = arr[end] - arr[start];

		int subtractPoint = result - m;
		if (subtractPoint >= 0 && subtractResult > subtractPoint)
		{
			subtractResult = subtractPoint;
			answer = result;
		}
	}

	cout << answer;
	return 0;
}