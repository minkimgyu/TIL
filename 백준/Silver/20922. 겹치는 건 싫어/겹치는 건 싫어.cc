#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

const int maxSize = 200000;
int arr[maxSize];

const int maxItem = 100001;
int visit[maxItem];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	int start = 0;
	int end = 0;

	int maxOverlapCount = 0;
	int maxLength = 1;

	int answer = 0;

	visit[arr[start]] += 1;
	maxOverlapCount = 1;

	while (start < n)
	{
		// 다음 것을 비교해서 확인해주기
		if (end < n - 1 && visit[arr[end + 1]] + 1 <= k) // 하나를 추가할꺼니깐 1을 더해서 비교해준다.
		{
			end++;
			visit[arr[end]] += 1;

			maxOverlapCount = max(maxOverlapCount, visit[arr[end]]);
			maxLength++;
			answer = max(maxLength, answer);
		}
		else
		{
			visit[arr[start]] -= 1;
			start++;
			maxLength--;
		}
	}

	cout << answer;
	return 0;
}