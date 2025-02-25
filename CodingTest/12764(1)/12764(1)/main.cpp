#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int result = 0;
int sitUseArr[100000];

int n;
pair<int, int> timeArr[100000];

struct Compare
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.first > b.first;
	}
};

// ������ �ð�, ���� �¼� ��ȣ
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> timePQ;

// �¼��� �ּ� ��ȣ
priority_queue<int, vector<int>, greater<int>> sitPQ;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> timeArr[i].first >> timeArr[i].second;
		sitPQ.push(i);
	}

	sort(timeArr, timeArr + n, compare);

	for (int i = 0; i < n; i++)
	{
		if (timePQ.empty() == true)
		{
			int sitNumber = sitPQ.top();
			sitPQ.pop();

			sitUseArr[sitNumber] += 1;
			timePQ.push({ timeArr[i].second, sitNumber });
		}
		else
		{
			// ���⼭ �ϳ��� ���°� �ƴ϶� ������ ���� �� �ִٴ� ���� �˾ƾ��Ѵ�.
			while (timePQ.empty() == false && timePQ.top().first <= timeArr[i].first)
			{
				int sitNumber = timePQ.top().second;
				timePQ.pop();
				sitPQ.push(sitNumber); // ��Ʈ �ѹ��� �ٽ� �־��ش�.
			}

			// �ٽ� �־��ش�.
			int sitNumber = sitPQ.top();
			sitPQ.pop();

			sitUseArr[sitNumber] += 1;
			timePQ.push({ timeArr[i].second, sitNumber });
		}

		int useSize = timePQ.size();
		result = max(result, useSize);
	}

	cout << result << '\n';
	for (int i = 0; i < result; i++)
	{
		cout << sitUseArr[i];
		if (i != result - 1) cout << " ";
	}

	return 0;
}