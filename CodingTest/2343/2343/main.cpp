#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; // n이 강의 개수, m이 블루레이 개수
	cin >> n >> m;

	int left = 0;
	int right = 0;

	// 시간 복잡도 : n + log(n) * n
	// 최악의 경우 : n + n * n

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		right += arr[i];
		
		if (i == 0) left = arr[i];
		else { if (arr[i] > left) left = arr[i]; }
	}

	// left가 블루레이 크기 중 가장 작은 것
	// right가 블루레이 크기 중 가장 큰 것

	while (left <= right) // left 값이 right 값보다 큰 경우 답을 찾은 것임 --> count == m이 나와도 중간 값이 최적의 해가 아닐 수 있기 때문에 계속 실행시켜줘야함
	{
		int mid = (int)((left + right) / 2);

		int sum = 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + arr[i] > mid)
			{
				sum = 0;
				count++;
			}
			sum += arr[i];
		}

		if (sum > 0) count++; // 마지막에 남은 sum 값이 존재한다면 count 값을 1 올려준다.

		if (count > m) // 나눈 블루레이 개수가 주어진 값보다 큰 경우 --> 중간 값이 작다는 의미를 가짐
		{
			left = mid + 1;
		}
		else // 반대의 경우 right를 -1 해준다.
		{
			right = mid - 1;
		}
	}
	
	cout << left;

	return 0;
}