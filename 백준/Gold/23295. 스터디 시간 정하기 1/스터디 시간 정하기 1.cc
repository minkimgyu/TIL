#include <iostream>
#include <vector>
using namespace std;

const int maxSize = 100000 + 5;
int sum[maxSize];

int sum1[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t;
	cin >> n >> t;

	int maxEnd = 0;

	for (int i = 0; i < n; i++)
	{
		int timeCount;
		cin >> timeCount;

		for (int j = 0; j < timeCount; j++)
		{
			int start, end;
			cin >> start >> end;

			maxEnd = max(maxEnd, end);
			sum[start] += 1;
			sum[end] -= 1;
		}
	}

	int maxSum = 0;
	int start, end;

	start = 0;
	end = t;

	sum1[0] = sum[0];
	for (int i = 1; i <= maxEnd; i++)
	{
		sum1[i] = sum1[i - 1] + sum[i];
	}

	for (int i = 0; i < t; i++)
	{
		maxSum += sum1[i];
	}

	int maxResult = maxSum;

	for (int i = t; i <= maxEnd; i++)
	{
		int one = i - t;
		int two = i;

		maxSum += sum1[two] - sum1[one];
		if (maxResult < maxSum) // maxSum이 더 큰 경우
		{
			maxResult = maxSum; // 업데이트
			start = one + 1;
			end = two + 1;
		}
	}

	cout << start << " " << end;
	return 0;
}