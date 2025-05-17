#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxSize = 1000 + 5;
int dp[maxSize][maxSize];

int result = -1;
string resultS;
string s1, s2;

void dfs(pair<int, int> start)
{
	if (dp[start.first][start.second] == 0) return;

	pair<int, int> left = { start.first, start.second - 1 };
	pair<int, int> up = { start.first - 1, start.second };
	pair<int, int> cross = { start.first - 1, start.second - 1 };

	if (dp[up.first][up.second] == dp[start.first][start.second])
	{
		dfs(up);
	}
	else if (dp[left.first][left.second] == dp[start.first][start.second])
	{
		dfs(left);
	}
	else
	{
		resultS.push_back(s1[start.first - 1]);
		dfs(cross);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	int s1Size = s1.size();
	int s2Size = s2.size();

	for (int i = 0; i <= s1Size; i++)
	{
		for (int j = 0; j <= s2Size; j++)
		{
			if (i == 0 || j == 0) continue;
			else if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	for (int i = 0; i <= s1Size; i++)
	{
		for (int j = 0; j <= s2Size; j++)
		{
			if (result < dp[i][j])
			{
				result = dp[i][j];
			}
		}
	}

	if (result == 0)
	{
		cout << result;
	}
	else
	{
		dfs({ s1Size, s2Size });

		cout << result << '\n';
		for (int i = resultS.size() - 1; i > -1; i--)
		{
			cout << resultS[i];
		}
	}
	
	return 0;
}