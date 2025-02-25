#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

const int maxSize = 1000000;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start = 0;
	int end = 0;
	int oddCount = 0;

	int result = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		if (arr[0] % 2 == 0) cout << 1;
		else cout << 0;

		return 0;
	}

	if (arr[end] % 2 != 0) oddCount++; // 0번째 값이 홀수이면 oddCount를 1 더해준다.
	else result = 1; // 아니면 부분 수열의 길이가 최소 1 이상이라는 소리임

	while (start < n)
	{
		if (end < n - 1 && (oddCount == k && arr[end + 1] % 2 != 0) == false) // (end + 1)의 값이 oddCount 범위 내에 있는 경우
		{
			end++;
			if (arr[end] % 2 != 0) oddCount++; // end의 값이 홀수라면 더해주기
		}
		else
		{
			if (arr[start] % 2 != 0) oddCount--; // start의 값이 홀수라면 빼주기
			start++;
		}

		if (oddCount <= k)
		{
			// 홀수 개수가 k개 이하인 경우만 계산해준다.
			result = max(result, end - start + 1 - oddCount);
		}
	}

	cout << result;

	return 0;
}