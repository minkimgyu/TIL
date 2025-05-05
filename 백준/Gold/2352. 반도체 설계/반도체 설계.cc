#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 40000 + 5;
int arr[maxSize];
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
			int dpIndex = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

			if (dp.size() == dpIndex)
			{
				dp.push_back(arr[i]);
			}
			else
			{
				dp[dpIndex] = arr[i];
			}
		}
	}

	cout << dp.size();
	return 0;
}