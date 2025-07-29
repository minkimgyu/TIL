#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int itemSize = 5000 + 5;
const int moneySize = 10000 + 5;

pair<int, int> arr[itemSize];
int dp[moneySize];

int n;

int dfs(int totalMoney)
{
	if (dp[totalMoney] != 0) return dp[totalMoney];

	for (int i = 0; i < n; i++)
	{
		if (totalMoney - arr[i].second < 0) continue;

		int nxtMoney = totalMoney - arr[i].second;
		dp[totalMoney] = max(dp[totalMoney], dfs(nxtMoney) + arr[i].first);
	}

	return dp[totalMoney];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1)
	{
		string tP;
		cin >> n >> tP;

		if (n == 0 && tP == "0.00") break;

		int totalPrice = round(stof(tP) * 100);

		for (int i = 0; i < n; i++)
		{
			int c;
			string s;
			cin >> c >> s;
			int itemPrice = round(stof(s) * 100);

			arr[i] = { c, itemPrice };
		}

		cout << dfs(totalPrice) << '\n';

		// 배열 청소 필요

		for (int i = 0; i < itemSize; i++)
		{
			arr[i] = { 0, 0 };
		}

		for (int i = 0; i < moneySize; i++)
		{
			dp[i] = 0;
		}
	}

	return 0;
}