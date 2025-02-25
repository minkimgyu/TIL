#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int colSize = 3;
int arr[100000][colSize];
int dp[100000][colSize];

const int offsetSize = 4;
pair<int, int> offsets[offsetSize] =
{
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
};

vector<int> result;

int main()
{
	int outIndex = 0;

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

			dp[i][0] = 1000001;
			dp[i][1] = 1000001;
			dp[i][2] = 1000001;
		}

		dp[0][1] = arr[0][1];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < colSize; j++)
			{
				for (int k = 0; k < offsetSize; k++)
				{
					int r = i + offsets[k].first;
					int c = j + offsets[k].second;

					if (r < 0 || r >= n || c < 0 || c >= colSize) continue;
					dp[r][c] = min(dp[r][c], dp[i][j] + arr[r][c]);
				}
			}
		}

		result.push_back(dp[n - 1][1]);
	}

	string colma = ". ";

	int resultSize = result.size();
	for (int i = 0; i < resultSize; i++)
	{
		cout << i + 1;
		cout << colma;
		cout << result[i];

		if (i != resultSize - 1) cout << '\n';
	}
	
	return 0;
}