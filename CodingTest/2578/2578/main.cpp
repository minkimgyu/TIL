#include <iostream>
#include <map>
using namespace std;

const int width = 5;
int mapArr[width][width];

map<int, pair<int, int>> posMap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int item;
			cin >> item;
			
			mapArr[i][j] = item;
			posMap[item] = { i, j };
		}
	}

	int callCount = 0;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < width; j++)
		{
			callCount++;
			int result = 0;

			int input;
			cin >> input;
			mapArr[posMap[input].first][posMap[input].second] = -1;


			for (int r = 0; r < width; r++)
			{
				bool cClear = true;
				for (int c = 0; c < width; c++)
				{
					if (mapArr[r][c] != -1)
					{
						cClear = false;
						break;
					}
				}

				if (cClear == true) result++;
			}

			for (int c = 0; c < width; c++)
			{
				bool rClear = true;
				for (int r = 0; r < width; r++)
				{
					if (mapArr[r][c] != -1)
					{
						rClear = false;
						break;
					}
				}

				if (rClear == true) result++;
			}

			bool xClear = true;
			for (int c = 0; c < width; c++)
			{
				if (mapArr[c][c] != -1)
				{
					xClear = false;
					break;
				}
			}

			if (xClear == true) result++;

			xClear = true;
			for (int c = 0; c < width; c++)
			{
				if (mapArr[width - 1 - c][c] != -1)
				{
					xClear = false;
					break;
				}
			}

			if (xClear == true) result++;

			if (result >= 3)
			{
				cout << callCount;
				return 0;
			}
		}
	}

	return 0;
}