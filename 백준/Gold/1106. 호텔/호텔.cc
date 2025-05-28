#include <iostream>
using namespace std;

const int maxPeople = 1000 + 95;
int dp[maxPeople];

pair<int, int> city[20 + 5];

const int maxCost = 100 * 1000 + 5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n;
	cin >> c >> n;

	for (int i = 0; i < maxPeople; i++) dp[i] = maxCost;

	for (int j = 0; j < n; j++)
	{
		cin >> city[j].first >> city[j].second;
	}

	dp[0] = 0;

	for (int i = 0; i <= c; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + city[j].second >= maxPeople) continue;
			dp[i + city[j].second] = min(dp[i + city[j].second], dp[i] + city[j].first);
		}
	}

	int result = maxCost;
	for (int i = c; i < maxPeople; i++)
	{
		result = min(result, dp[i]);
	}

	cout << result;
	return 0;
}