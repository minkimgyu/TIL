#include <iostream>
#include <string>
using namespace std;

const int maxSize = 750 + 5;
int arr[maxSize][maxSize];

// ↙ 방향 부분합
int dp1[maxSize][maxSize];

// ↘ 방향 부분합
int dp2[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c;
	cin >> r >> c;
	cin.ignore();

	for (int i = 0; i < r; i++)
	{
		string s;
		getline(cin, s);

		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	 // ↙ 방향 부분합
	for (int i = 0; i < c; i++)
	{
		int startCol = i;
		int startRow = 0;

		for (int j = 0; j < min(i + 1, r); j++)
		{
			// 0, 1, 2, 3, 4
			if (startRow == 0)
			{
				dp1[startRow][startCol] = arr[startRow][startCol];
			}
			else
			{
				dp1[startRow][startCol] = arr[startRow][startCol] + dp1[startRow - 1][startCol + 1];
			}

			startCol--;
			startRow++;
		}
	}

	for (int i = 1; i < r; i++)
	{
		int startCol = c - 1;
		int startRow = i;

		for (int j = 0; j < r - i; j++)
		{
			// 0, 1, 2, 3, 4
			if (startCol == c - 1)
			{
				dp1[startRow][startCol] = arr[startRow][startCol];
			}
			else
			{
				dp1[startRow][startCol] = arr[startRow][startCol] + dp1[startRow - 1][startCol + 1];
			}

			startCol--;
			startRow++;
		}
	}

	// ↘ 방향 부분합
	for (int i = c - 1; i > -1; i--)
	{
		int startCol = i;
		int startRow = 0;

		for (int j = 0; j < min(c - i, r); j++)
		{
			// 0, 1, 2, 3, 4
			if (startRow == 0)
			{
				dp2[startRow][startCol] = arr[startRow][startCol];
			}
			else
			{
				dp2[startRow][startCol] = arr[startRow][startCol] + dp2[startRow - 1][startCol - 1];
			}

			startCol++;
			startRow++;
		}
	}

	for (int i = 1; i < r; i++)
	{
		int startCol = 0;
		int startRow = i;

		for (int j = 0; j < min(r - i, c); j++)
		{
			// 0, 1, 2, 3, 4
			if (startCol == 0)
			{
				dp2[startRow][startCol] = arr[startRow][startCol];
			}
			else
			{
				dp2[startRow][startCol] = arr[startRow][startCol] + dp2[startRow - 1][startCol - 1];
			}

			startCol++;
			startRow++;
		}
	}
	
	int maxResult = 0;
	bool canFind = false;

	int maxResultSize = min(r, c) / 2 + 1;

	for (int k = 0; k < maxResultSize; k++)
	{
		for (int i = k; i < r - k; i++)
		{
			for (int j = k; j < c - k; j++)
			{
				int left, right, bottom1, bottom2;

				pair<int, int> rightTopOffset = { i - (k + 1), j + (k + 1) };
				pair<int, int> leftTopOffset = { i - (k + 1), j - (k + 1) };

				if (rightTopOffset.first < 0 || rightTopOffset.second - k < 0) left = dp1[i][j - k];
				else left = dp1[i][j - k] - dp1[rightTopOffset.first][rightTopOffset.second - k];

				if (leftTopOffset.first < 0 || leftTopOffset.second + k >= c) right = dp2[i][j + k];
				else right = dp2[i][j + k] - dp2[leftTopOffset.first][leftTopOffset.second + k];

				if (rightTopOffset.first + k < 0 || c <= rightTopOffset.second)
				{
					bottom1 = dp1[i + k][j];
				}
				else
				{
					bottom1 = dp1[i + k][j] - dp1[rightTopOffset.first + k][rightTopOffset.second];
				}


				if (leftTopOffset.first + k < 0 || leftTopOffset.second < 0) bottom2 = dp2[i + k][j];
				else bottom2 = dp2[i + k][j] - dp2[leftTopOffset.first + k][leftTopOffset.second];


				if (left == k + 1 && 
					right == k + 1 && 
					bottom1 == k + 1 && 
					bottom2 == k + 1)
				{
					maxResult = k + 1;
					canFind = true;
					break;
				}
			}

			if (canFind == true)
			{
				canFind = false;
				break;
			}
		}
	}

	cout << maxResult;
	return 0;
}