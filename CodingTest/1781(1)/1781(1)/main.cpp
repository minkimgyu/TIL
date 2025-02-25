#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int indexCount[200001];
pair<int, int> arr[200001];
int n, result, maxDeadline, index = 0;

priority_queue<int> pQ;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int deadline, cupCount;

		cin >> deadline >> cupCount;

		if (maxDeadline < deadline) maxDeadline = deadline;

		indexCount[deadline] += 1;

		arr[i].first = deadline;
		arr[i].second = cupCount;
	}

	sort(arr, arr + n, compare);

	for (int i = maxDeadline; i > 0; i--)
	{
		for (int j = 0; j < indexCount[i]; j++)
		{
			pQ.push(arr[index].second);
			index++;
		}

		if (pQ.empty() == true) continue;

		int top = pQ.top();
		pQ.pop();
		result += top;
	}

	cout << result;

	return 0;
}