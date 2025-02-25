#include <iostream>
#include <string>
using namespace std;

int n;
const int maxSize = 64 + 5;
int arr[maxSize][maxSize];

void dfs(int row, int col, int size)
{
	if (size == 1)
	{
		cout << arr[row][col];
		return;
	}
	else
	{
		int zCount = 0;
		int oCount = 0;

		for (int i = row; i < row + size; i++)
		{
			for (int j = col; j < col + size; j++)
			{
				if (arr[i][j] == 0) zCount++;
				else oCount++;
			}
		}

		if (zCount > 0 && oCount == 0)
		{
			cout << 0;
			return;
		}
		else if (oCount > 0 && zCount == 0)
		{
			cout << 1;
			return;
		}
	}

	int a = size / 2 * 0;
	int b = size / 2 * 1;

	cout << "(";

	dfs(row + a, col + a, size / 2);
	dfs(row + a, col + b, size / 2);

	dfs(row + b, col + a, size / 2);
	dfs(row + b, col + b, size / 2);

	cout << ")";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string line;
		getline(cin, line);

		for (int j = 0; j < n; j++)
		{
			arr[i][j] = line[j] - '0';
		}
	}

	dfs(0, 0, n);
	return 0;
}