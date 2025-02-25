#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int maxSize = 2005;
long long int arr[maxSize];

//unordered_set<long long int> set;
int result = 0;

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

	// 1, 2, 3, 5, 5, 5 --> 이런 식으로 있을 수도 있음
	// upper_bound와 lower_bound를 빼서 값을 찾자

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			long long int sum = arr[i] + arr[j];
			//if (set.find(sum) != set.end()) continue; // 이미 이전에 찾은 경우

			long long int* upperBound = upper_bound(arr + j + 1, arr + n, sum);
			long long int* lowerBound = lower_bound(arr + j + 1, arr + n, sum);

			int numCount = upperBound - lowerBound;
			if (numCount > 0)
			{
				//set.insert(sum);
				result += numCount;
			}
		}
	}

	cout << result;
	return 0;
}