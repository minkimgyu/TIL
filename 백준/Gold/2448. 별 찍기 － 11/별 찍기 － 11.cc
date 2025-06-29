#include <iostream>
using namespace std;

const int length = (1024 * 3) / 3 * 5 + (1024 * 3) / 3 - 1 + 5;
int arr[length][length];

int col;
int row;

void dfs(pair<int, int> pos, int row, int col)
{
	if (row == 3 && col == 5)
	{
		arr[pos.first][pos.second] = 0;
		arr[pos.first][pos.second + 1] = 0;
		arr[pos.first][pos.second + 2] = 1;
		arr[pos.first][pos.second + 3] = 0;
		arr[pos.first][pos.second + 4] = 0;

		arr[pos.first + 1][pos.second] = 0;
		arr[pos.first + 1][pos.second + 1] = 1;
		arr[pos.first + 1][pos.second + 2] = 0;
		arr[pos.first + 1][pos.second + 3] = 1;
		arr[pos.first + 1][pos.second + 4] = 0;

		arr[pos.first + 2][pos.second] = 1;
		arr[pos.first + 2][pos.second + 1] = 1;
		arr[pos.first + 2][pos.second + 2] = 1; 
		arr[pos.first + 2][pos.second + 3] = 1;
		arr[pos.first + 2][pos.second + 4] = 1;
	}
	else
	{
		// 40 20 10 5
		dfs({ pos.first, pos.second + (col / 4) + 1 }, row / 2, col / 2); // 상단

		dfs({ pos.first + (row / 2),  pos.second }, row / 2, col / 2); // 하단 왼쪽

		dfs({ pos.first + (row / 2),  pos.second + (col / 2) + 1 }, row / 2, col / 2); // 하단 오른쪽
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	col = (n / 3) * 5 + (n / 3) - 1;
	row = n;

	dfs({0, 0}, row, col);


	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 1) cout << "*";
			else cout << " ";
		}

		if(i != row - 1) cout << '\n';
	}

	return 0;
}