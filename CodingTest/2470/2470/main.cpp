#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int arrSize = 100000;
int arr[arrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start, end;

	int minValue = 2000000001;
	int minStart = 0;
	int minEnd = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	start = 0;
	end = n - 1;

	while (start < end)
	{
		int sum = arr[start] + arr[end];
		int absSum = abs(sum);

		// 여기에 가장 비슷한 값을 저장하는 코드를 추가한다.
		if (absSum < minValue)
		{
			minValue = absSum;
			minStart = start;
			minEnd = end;
		}

		if (sum > 0)
		{
			end--;
		}
		else if(sum < 0)
		{
			start++;
		}
		else
		{
			start++;
			end--;
		}
	}

	vector<int> result = { arr[minStart], arr[minEnd] };
	sort(result.begin(), result.end());

	cout << result[0] << " " << result[1];
	return 0;
}