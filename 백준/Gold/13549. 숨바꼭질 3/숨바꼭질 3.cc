#include <iostream>
#include <queue>
using namespace std;

const int maxSize = 100000 + 5;
int timeArr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	if (n == k)
	{
		cout << 0;
		return 0;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, n });

	timeArr[n] = 0;
	for (int i = 0; i < maxSize; i++) timeArr[i] = maxSize;

	while (q.empty() == false)
	{
		pair<int, int> top = q.top(); q.pop();

		if (top.second + 1 < maxSize)
		{
			if (timeArr[top.second + 1] > top.first + 1)
			{
				timeArr[top.second + 1] = top.first + 1;
				q.push({ top.first + 1, top.second + 1 });
			}
		}

		if (top.second - 1 >= 0)
		{
			if (timeArr[top.second - 1] > top.first + 1)
			{
				timeArr[top.second - 1] = top.first + 1;
				q.push({ top.first + 1, top.second - 1 });
			}
		}

		if (top.second * 2 < maxSize)
		{
			if (timeArr[top.second * 2] > top.first)
			{
				timeArr[top.second * 2] = top.first;
				q.push({ top.first, top.second * 2 });
			}
		}
	}

	cout << timeArr[k];
	return 0;
}