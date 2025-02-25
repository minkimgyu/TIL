#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 1000;
long long int arr[maxSize];

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

	// i, j 합 == k - l

	vector<long long int> sumVec;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			long long int sum = arr[x] + arr[y];
			sumVec.push_back(sum);
		}
	}

	sort(sumVec.begin(), sumVec.end());
	long long int result = -1;

	for (int k = 0; k < n; k++)
	{
		for (int z = 0; z < n; z++)
		{
			// arr[x] + arr[y] + arr[z] = arr[k]
			// arr[x] + arr[y] = arr[k] - arr[z] 를 찾는다.

			long long int sub = arr[k] - arr[z];
			bool canFind = binary_search(sumVec.begin(), sumVec.end(), sub);

			if (canFind == true)
			{
				//가능한 arr[k] 중 최대값을 찾는다.
				result = max(result, arr[k]);
			}
		}
	}

	cout << result;

	return 0;
}