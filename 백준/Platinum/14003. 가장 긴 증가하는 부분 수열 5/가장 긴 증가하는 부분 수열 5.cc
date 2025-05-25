#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];

vector<int> dp;
vector<int> results;
stack<pair<int, int>> st; // 최종적으로 바뀐 값을 봐야하기 때문에 top에서 내려가야한다.

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
			st.push({ 0, arr[i] });
			dp.push_back(arr[i]);
		}
		else
		{
			auto index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

			if (index == dp.size()) dp.push_back(arr[i]);
			else dp[index] = arr[i];
			st.push({ index, arr[i] });
		}
	}

	int result = dp.size();
	int popIndex = result - 1;

	cout << result << '\n';
	for (int i = 0; i < n; i++)
	{
		pair<int, int> topItem = st.top(); st.pop();
		if (topItem.first == popIndex)
		{
			results.push_back(topItem.second);
			popIndex--;
		}
	}

	for (int i = results.size() - 1; i > -1; i--)
	{
		cout << results[i];
		if (i != 0) cout << " ";
	}

	return 0;
}