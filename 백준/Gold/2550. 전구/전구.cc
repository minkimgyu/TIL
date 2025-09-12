#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxSize = 10000 + 5;
int arr[maxSize];
int order[maxSize];

int dp[maxSize];
int trackArr[maxSize];

vector<int> results;

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

	for (int i = 0; i < n; i++)
	{
		int numToFind;
		cin >> numToFind;

		order[numToFind] = i;
	}

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		trackArr[i] = -1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (order[arr[j]] < order[arr[i]])
			{
				if (dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					trackArr[i] = j; // 역추적
				}
			}
		}
	}

	int result = 0; // 최소 1개 연속
	int maxIdx = -1;

	for (int i = 0; i < n; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
			maxIdx = i;
		}
	}


	cout << result << '\n';
	while (maxIdx != -1)
	{
		results.push_back(arr[maxIdx]);
		maxIdx = trackArr[maxIdx];
	}

	sort(results.begin(), results.end());

	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i] << " ";
	}

	return 0;
}