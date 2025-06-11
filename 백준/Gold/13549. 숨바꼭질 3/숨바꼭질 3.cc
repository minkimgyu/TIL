#include <iostream>
#include <deque>
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

	deque<pair<int, int>> q;
	q.push_back({ 0, n });

	for (int i = 0; i < maxSize; i++) timeArr[i] = maxSize;

	while (q.empty() == false)
	{
		pair<int, int> top = q.front(); q.pop_front();

		if (top.second * 2 < maxSize && timeArr[top.second * 2] > top.first)
		{
			timeArr[top.second * 2] = top.first;
			q.push_front({ top.first, top.second * 2 });
		}

		if (top.second - 1 >= 0 && timeArr[top.second - 1] > top.first + 1)
		{
			timeArr[top.second - 1] = top.first + 1;
			q.push_back({ top.first + 1, top.second - 1 });
		}

		if (top.second + 1 < maxSize && timeArr[top.second + 1] > top.first + 1)
		{
			timeArr[top.second + 1] = top.first + 1;
			q.push_back({ top.first + 1, top.second + 1 });
		}
	}

	cout << timeArr[k];
	return 0;
}