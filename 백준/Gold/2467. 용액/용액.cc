#include <iostream>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

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

	int result;
	int left = 0;
	int right = n - 1;

	pair<int, int> resultIdx;
	int closeNum = 2000000000 + 5;

	while (left < right)
	{
		int sum = arr[left] + arr[right];

		if (abs(sum) < closeNum) // 절대값이 이전 값보다 작은 경우 업데이트하기
		{
			closeNum = abs(sum);
			resultIdx = { left, right };
		}

		if (sum < 0)
		{
			left++;
		}
		else if (sum > 0)
		{
			right--;
		}
		else
		{
			left++;
			right--;
		}
	}

	cout << arr[resultIdx.first] << " " << arr[resultIdx.second];
	return 0;
}