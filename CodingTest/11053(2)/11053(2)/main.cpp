#include <iostream>
#include <algorithm>
using namespace std;

int n;

const int maxArrSize = 1000;
int arr[maxArrSize];
int dp[maxArrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1; // 1로 초기화 --> 자기 자신이 가장 마지막이므로 항상 길이는 1부터 시작한다.
	}

	int result = 1; // 엣지 케이스: n이 1인 경우에 1을 출력해야한다.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j]) // 앞선 값 중 작은 값들을 선택한다.
			{
				dp[i] = max(dp[i], dp[j] + 1);
				result = max(dp[i], result);
			}
		}
	}

	cout << result;
	return 0;
}