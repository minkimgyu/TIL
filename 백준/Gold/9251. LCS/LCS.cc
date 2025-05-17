#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int maxSize = 1000 + 5;
int dp[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
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

	int result = 0;

	for (int i = 0; i <= s1Size; i++)
	{
		for (int j = 0; j <= s2Size; j++)
		{
			result = max(result, dp[i][j]);
		}
	}

	cout << result;
	return 0;
}