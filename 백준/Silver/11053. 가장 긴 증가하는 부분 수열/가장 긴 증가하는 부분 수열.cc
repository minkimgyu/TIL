#include <iostream>
#include <algorithm>
using namespace std;

const int dpSize = 1000;
int dp[1000];

int arr[1000];

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
	}

	for (int i = 0; i < dpSize; i++) dp[i] = 1;

	// A(i)가 가장 마지막으로 연속되는 수열로 생각하고 접근해보자

	// 만약 배열이 {1}이면 답도 1이 나와야한다.
	int result = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] <= arr[j]) continue;

			// 앞선 dp값보다 작은 dp값에서 +1 한 값이 수열의 가능한 길이임
			dp[i] = max(dp[i], dp[j] + 1);

			if (result < dp[i]) result = dp[i];
		}
	}

	cout << result;
	return 0;
}