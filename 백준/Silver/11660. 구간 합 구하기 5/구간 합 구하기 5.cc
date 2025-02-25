#include <iostream>
#include <vector>
using namespace std;

int n, m;

const int maxSize = 1024;
int dp[maxSize][maxSize];

// dp에 들어갈 수 있는 최대값은 1024 * 1024 * 1000이다
// 따라서 1,048,576,000는 int의 범위을 넘지 못하므로 int로 써도 된다.

// N이 1인 경우
//

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int item;
			cin >> item;

			dp[i][j] = item;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int left = 0;
			int up = 0;
			int cross = 0;

			if (j - 1 >= 0)
			{
				left = dp[i][j - 1];
			}

			if (i - 1 >= 0)
			{
				up = dp[i - 1][j];
			}

			if (i - 1 >= 0 && j - 1 >= 0)
			{
				cross = dp[i - 1][j - 1];
			}

			dp[i][j] = dp[i][j] + left + up - cross; // cross를 겹치기 때문에 빼준다.
		}
	}

	for (int i = 0; i < m; i++)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		r1 -= 1;
		c1 -= 1;

		r2 -= 1;
		c2 -= 1;

		int left = 0;
		int up = 0;
		int cross = 0;

		if (r1 - 1 >= 0 && c1 - 1 >= 0)
		{
			cross = dp[r1 - 1][c1 - 1];
		}

		if (r1 - 1 >= 0)
		{
			up = dp[r1 - 1][c2];
		}

		if (c1 - 1 >= 0)
		{
			left = dp[r2][c1 - 1];
		}

		cout << dp[r2][c2] - (left + up) + cross; // cross를 겹치기 때문에 빼준다.
		if (i != m - 1) cout << '\n';
	}

	return 0;
}