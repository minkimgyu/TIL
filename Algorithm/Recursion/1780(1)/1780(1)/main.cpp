#include <iostream>
using namespace std;

int n;
const int maxSize = 2187 + 5;

int arr[maxSize][maxSize];

int mSize = 0;
int zSize = 0;
int pSize = 0;

// y, x
void dfs(int row, int col, int size)
{
	if (size == 1)
	{
		if (arr[row][col] == -1) mSize++;
		else if (arr[row][col] == 0) zSize++;
		else if (arr[row][col] == 1) pSize++;
		
		return;
	}
	else
	{
		int mmSize = 0;
		int mzSize = 0;
		int mpSize = 0;

		for (int i = row; i < row + size; i++)
		{
			for (int j = col; j < col + size; j++)
			{
				if (arr[i][j] == -1) mmSize++;
				else if (arr[i][j] == 0) mzSize++;
				else if (arr[i][j] == 1) mpSize++;
			}
		}

		// mmSize > 0 && (mzSize == 0 && mpSize == 0)
		// mzSize > 0 && (mmSize == 0 && mpSize == 0)
		// mpSize > 0 && (mmSize == 0 && mzSize == 0)

		// 하나의 숫자로 범위가 이루어져있다.
		if (mmSize > 0 && (mzSize == 0 && mpSize == 0) ||
			mzSize > 0 && (mmSize == 0 && mpSize == 0) ||
			mpSize > 0 && (mmSize == 0 && mzSize == 0))
		{
			int b = size * size;
			mSize += mmSize / b;
			zSize += mzSize / b;
			pSize += mpSize / b;
			return;
		}
	}

	// 0, 1, 2
	// size == 3

	int a = size / 3 * 0;
	int b = size / 3 * 1;
	int c = size / 3 * 2;

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

	cout << mSize << '\n';
	cout << zSize << '\n';
	cout << pSize;

	return 0;
}