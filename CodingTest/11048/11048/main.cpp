#include <iostream>
using namespace std;

const int dpSize = 1001;
int dp[dpSize][dpSize]{ 0 };
int arr[dpSize][dpSize]{ 0 };

const int offsetSize = 3;
pair<int, int> offset[offsetSize] = { {0, 1}, {1, 0}, {1, 1} };

// 간단한 dp 문제
// 값을 더하면서 더 큰 수를 남겨준다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int z = 0; z < offsetSize; z++)
			{
				int originValue = dp[i][j];

				int y = i + offset[z].second;
				int x = j + offset[z].first;

				if (y >= r || x >= c) continue;

				int result = originValue + arr[y][x];

				if (dp[y][x] >= result) continue;

				dp[y][x] = result;
			}
		}
	}

	cout << dp[r - 1][c - 1];

	return 0;
}