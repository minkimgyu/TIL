#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxSize = 1000000 + 5;
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
			if (dp.size() == dpIndex) // 가장 큰 경우는 dp 배열에 추가한다.
			{
				dp.push_back(arr[i]);
			}
			else // 아닌 경우는 위치를 찾아서 교체한다.
			{
				dp[dpIndex] = arr[i];
			}
		}
	}

	cout << dp.size();
	return 0;
}