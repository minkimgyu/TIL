#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

// 내림차순으로 정렬해서 푸는 문제
// arr[i] 값이 병렬로 나눠서 들 수 있는 가장 큰 값이기 때문에
// 해당 값 * 개수 --> 이런 식으로 maxWeight 값을 갱신해준다.

// 7
// 8
// 10
// 15

// 8 8 8 -- > 24
// 7 7 7 7 -> 28
// 이런 반례가 존재할 수 있기 때문에 모든 값을 검사해줘야한다.
//

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	int maxWeight = 0;

	for (int i = 0; i < n; i++)
	{
		if (i == 0) maxWeight = arr[i];
		else
		{
			int weight = arr[i] * (i + 1);
			if (weight > maxWeight) maxWeight = weight;
		}
	}

	cout << maxWeight;

	return 0;
}