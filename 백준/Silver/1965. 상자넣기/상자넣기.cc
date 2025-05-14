#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000 + 5];
vector<int> dp;

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
		if (dp.empty() == true)
		{
			dp.push_back(arr[i]);
		}
		else
		{
			int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			if (index < dp.size())
			{
				dp[index] = arr[i];
			}
			else
			{
				dp.push_back(arr[i]);
			}
		}
	}

	cout << dp.size();
	return 0;
}