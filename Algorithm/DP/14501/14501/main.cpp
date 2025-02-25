#include <iostream>
using namespace std;

const int maxSize = 16;
pair<int, int> arr[maxSize];

int n = 0;
int result = 0;

void dfs(int day, int cost)
{
	if (day > n + 1) return; // n보다 크면 리턴
	else if (day == n + 1)
	{
		result = max(result, cost);
		return;
	}

	result = max(result, cost);

	dfs(day + arr[day].first, cost + arr[day].second);
	dfs(day + 1, cost);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	dfs(1, 0);
	cout << result;
	return 0;
}