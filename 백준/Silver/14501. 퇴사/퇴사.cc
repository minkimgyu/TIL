#include <iostream>
#include <algorithm>
using namespace std;

int dp[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	pair<int, int>* talks = new pair<int, int>[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> talks[i].first >> talks[i].second;
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i + 1] = max(dp[i + 1], dp[i]); // 이 경우는 아무 것도 하지 않고 스킵하는 경우임
		dp[talks[i].first + i] = max(dp[talks[i].first + i], dp[i] + talks[i].second);
	}

	delete[] talks;

	cout << dp[n + 1];
	return 0;
}