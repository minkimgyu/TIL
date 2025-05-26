#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int maxSize = 100000 + 5;
pair<int, int> items[maxSize];
vector<int> dp;

vector<int> others;

stack<pair<int, pair<int, int>>> st;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> items[i].first >> items[i].second;
	}

	sort(items, items + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (dp.empty())
		{
			dp.push_back(items[i].second);
			st.push({ i, items[i] });
		}
		else
		{
			int idx = lower_bound(dp.begin(), dp.end(), items[i].second) - dp.begin();

			if (dp.size() == idx)
			{
				dp.push_back(items[i].second);
			}
			else
			{
				dp[idx] = items[i].second;
			}

			st.push({ idx, items[i] });
		}
	}

	int resultIdx = dp.size() - 1;

	while (st.empty() == false)
	{
		pair<int, pair<int, int>> topItem = st.top();
		st.pop();

		if (topItem.first == resultIdx)
		{
			resultIdx--;
		}
		else
		{
			others.push_back(topItem.second.first);
		}
	}

	sort(others.begin(), others.end());

	cout << others.size() << '\n';

	for (int i = 0; i < others.size(); i++)
	{
		cout << others[i];
		if (i != others.size() - 1) cout << '\n';
	}

	return 0;
}