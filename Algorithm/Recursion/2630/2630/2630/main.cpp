#include <iostream>
using namespace std;

int n;

const int maxSize = 128 + 5;
int arr[maxSize][maxSize];

int wColor = 0;
int bColor = 0;

void dfs(int row, int col, int size)
{
	if (size == 1)
	{
		if (arr[row][col] == 0) wColor++;
		else bColor++;

		return;
	}
	else
	{
		int twColor = 0;
		int tbColor = 0;

		for (int i = row; i < row + size; i++)
		{
			for (int j = col; j < col + size; j++)
			{
				if (arr[i][j] == 0) twColor++;
				else tbColor++;
			}
		}

		// 둘 중 한 색깔만 있는 경우
		if (twColor > 0 && tbColor == 0 ||
			tbColor > 0 && twColor == 0)
		{
			int maxSize = size * size;
			wColor += twColor / maxSize;
			bColor += tbColor / maxSize;
			return;
		}
	}

	int a = size / 2 * 0;
	int b = size / 2 * 1;

	dfs(row + a, col + a, size / 2);
	dfs(row + b, col + a, size / 2);

	dfs(row + a, col + b, size / 2);
	dfs(row + b, col + b, size / 2);
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
	cout << wColor << "\n";
	cout << bColor;
	return 0;
}