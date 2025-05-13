#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> arr[100000 + 5];
priority_queue<int, vector<int>, greater<int>> pQ;

int tmp[100000 + 5];

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
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
		int h, o;
		cin >> h >> o;

		if (h > o)
		{
			arr[i].first = o;
			arr[i].second = h;
		}
		else
		{
			arr[i].first = h;
			arr[i].second = o;
		}
	}

	int d;
	cin >> d;

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
	{
		int LFirst = arr[i].second - d;

		while (pQ.empty() == false && pQ.top() < LFirst)
		{
			tmp[i] -= 1;
			pQ.pop();
		}

		if (arr[i].first >= LFirst)
		{
			tmp[i] += 1;
			pQ.push(arr[i].first);
		}
	}

	for (int i = 1; i < n; i++)
	{
		tmp[i] += tmp[i - 1];
	}

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result = max(result, tmp[i]);
	}

	cout << result;
	return 0;
}