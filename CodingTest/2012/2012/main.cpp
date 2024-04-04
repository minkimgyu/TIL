#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a < b;
}

// 정렬을 하는 접근은 좋았음
// 그러나 모든 수가 같을 경우 가장 작은 수가 0이 아닐 수도 있고
// 값을 +1 하면서 앞의 값이 뒤의 값보다 클수도 있다.
// 또한 뒤의 값이 더 크더라도 1만큼이 아니라 이보다 클 수 있으므로 이에 맞춰서 반례 대응을 해줘야한다.

// 그리고 n = 500,000일 경우 모든 수가 1이면 0+1+2+3+4.... 해서 21억을 넘을 수도 있으므로 long long을 사용한다.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	long long int* arr = new long long int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n, compare);

	long long int sum = 0;

	if (arr[0] > 1) // 가장 작은 수가 1이 아닌 경우
	{
		sum += arr[0] - 1;
		arr[0] = 1;
	}

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1]) // 서로 같은 경우
		{
			arr[i + 1] += 1;
			sum += 1;
		}
		else if (arr[i] > arr[i + 1]) // 앞선 값이 더 큰 경우
		{
			sum += arr[i] + 1 - arr[i + 1];
			arr[i + 1] = arr[i] + 1;
		}
		else if (arr[i] + 1 < arr[i + 1]) // 차이가 + 1 보다 큰 경우 --> 차이가 1인 경우는 아무 것도 하지 않음
		{
			sum += arr[i + 1] - (arr[i] + 1); // 둘을 빼준 값이 불만도임
			arr[i + 1] = arr[i] + 1; // 
		}
	}

	cout << sum;

	return 0;
}