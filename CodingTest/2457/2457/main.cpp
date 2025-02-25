#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> day;

int n;
const int monthCount = 12;
int lastDays[monthCount] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
pair<day, day> flowers[100001];

bool months[monthCount];

bool compare(pair<day, day> a, pair<day, day> b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;
	}

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
		pair<int, int> start, end;
		cin >> start.first >> start.second >> end.first >> end.second;

		flowers[i] = { start, end };
	}

	sort(flowers, flowers + n, compare);

	// 앞선 기간과 겹치는 경우
	// 커버되는 달이 많은 경우 + 뒤의 날짜가 긴 경우


	return 0;
}