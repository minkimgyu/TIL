#include <iostream>
using namespace std;

const int maxSize = 2187 + 5;
int n;
int arr[maxSize][maxSize]; // 2187

int mCount = 0;
int zCount = 0;
int pCount = 0;

void dfs(int row, int col, int size)
{
	if (size == 1)
	{
		if (arr[row][col] == -1) mCount++;
		else if (arr[row][col] == 0) zCount++;
		else pCount++;

		return;
	}
	else
	{
		int mmCount = 0;
		int mzCount = 0;
		int mpCount = 0;

		for (int i = row; i < row + size; i++)
		{
			for (int j = col; j < col + size; j++)
			{
				if (arr[i][j] == -1) mmCount++;
				else if (arr[i][j] == 0) mzCount++;
				else mpCount++;
			}
		}

		if (mmCount > 0 && (mzCount == 0 && mpCount == 0) ||
			mzCount > 0 && (mmCount == 0 && mpCount == 0) ||
			mpCount > 0 && (mmCount == 0 && mzCount == 0))
		{
			int totalSize = size * size;

			mCount += mmCount / totalSize;
			zCount += mzCount / totalSize;
			pCount += mpCount / totalSize;
			return;
		}
	}

	int a = size / 3 * 0; // 0, 0
	int b = size / 3 * 1; // 3, 1
	int c = size / 3 * 2; // 6, 2

	dfs(row + a, col + a, size / 3);
	dfs(row + b, col + a, size / 3);
	dfs(row + c, col + a, size / 3);

	dfs(row + a, col + b, size / 3);
	dfs(row + b, col + b, size / 3);
	dfs(row + c, col + b, size / 3);

	dfs(row + a, col + c, size / 3);
	dfs(row + b, col + c, size / 3);
	dfs(row + c, col + c, size / 3);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(0, 0, n);

	cout << mCount << '\n';
	cout << zCount << '\n';
	cout << pCount;
	return 0;
}