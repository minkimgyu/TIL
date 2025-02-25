#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100000 + 5;
pair<int, int> conference[maxSize];

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 시작 시간 기준으로 정렬
	// 시작 시간이 같다면 회의 시간이 짧은 것 기준으로 정렬
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> conference[i].first >> conference[i].second;
	}

	sort(conference, conference + n, compare);

	int result = 0;
	int endTime = 0;

	for (int i = 0; i < n; i++)
	{
		if (endTime > conference[i].first) continue;

		result++;
		endTime = conference[i].second;
	}

	cout << result;

	return 0;
}