#include <iostream>
using namespace std;

int n, d, k, c;

int inputArr[30000 + 3005];
int foodArr[3005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> d >> k >> c;

	for (int i = 1; i <= n; i++)
	{
		cin >> inputArr[i];
	}

	// 이어붙여주기
	for (int i = 1; i < k; i++)
	{
		inputArr[n + i] = inputArr[i];
	}

	int right = 1;

	int result = 0;

	// left, right 모두 1번 위치에 존재함
	int pickCount = 1;
	foodArr[inputArr[1]] = 1;

	for (int left = 1; left <= n; left++)
	{
		if (left > 1)
		{
			// 하나 이전 값을 빼준다.
			foodArr[inputArr[left - 1]] -= 1;
			if (foodArr[inputArr[left - 1]] == 0)
			{
				pickCount--;
				result = max(result, pickCount);
			}
		}

		// right 값을 맞춰준다.
		while (right - left < k - 1)
		{
			right++;

			foodArr[inputArr[right]] += 1;
			if (foodArr[inputArr[right]] == 1)
			{
				pickCount++;
				result = max(result, pickCount);
			}
		}

		if (right - left == k - 1) // k개인 경우 추가해주기
		{
			if (foodArr[c] == 0) // 쿠폰 번호에 해당하는 초밥을 먹지 않는 경우
			{
				result = max(result, pickCount + 1); // 1 추가
			}
		}
	}

	cout << result;

	return 0;
}