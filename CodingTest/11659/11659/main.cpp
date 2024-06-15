#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int* arr = new int[n];
	int* dp = new int[n]{0};
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		if (i > 0)
		{
			dp[i] = dp[i - 1] + arr[i];
		}
		else
		{
			dp[i] = arr[i];
		}
	}

	vector<int> results;

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		int result = 0;

		if (start == 1)
		{
			result = dp[end - 1];
		}
		else
		{
			result = dp[end - 1] - dp[start - 2];
		}

		results.push_back(result);
	}

	int resultSize = results.size();
	for (int i = 0; i < resultSize; i++)
	{
		cout << results[i];
		if (i != resultSize - 1) cout << '\n';
	}

	return 0;
}