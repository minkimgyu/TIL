#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, maxDay, result = 0;
pair<int, int> arr[10000];

int countByIndex[10001];

struct Comp
{
	// 이 경우는 일반적인 정렬과 반대로 정렬된다 --> 내림차순이 기본이기 때문
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.first < b.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pQ;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int money, day;
		cin >> money >> day;

		if (day > maxDay) maxDay = day;

		countByIndex[day] += 1;

		arr[i].first = money;
		arr[i].second = day;
	}

	sort(arr, arr + n, compare);
	int index = 0;

	for (int i = maxDay; i > 0; i--)
	{
		for (int j = 0; j < countByIndex[i]; j++)
		{
			pQ.push(arr[index]);
			index++;
		}

		if (pQ.empty() == true) continue;

		pair<int, int> top = pQ.top();
		pQ.pop();

		result += top.first;
	}

	cout << result;

	return 0;
}