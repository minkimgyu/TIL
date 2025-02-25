#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 210000000;

const int maxSize = 100 + 5;
int arr[maxSize][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		arr[start][end] = min(arr[start][end], cost);
	}

	for (int i = 1; i <= n; i++)
	{
		int viaIndex = i;

		for (int j = 1; j <= n; j++)
		{
			for (int z = 1; z <= n; z++)
			{
				int originCost = arr[j][z];
				int newCost = arr[j][viaIndex] + arr[viaIndex][z];

				arr[j][z] = min(originCost, newCost);
			}
		}
	}


	for (int j = 1; j <= n; j++)
	{
		for (int z = 1; z <= n; z++)
		{
			if (arr[j][z] == INF) arr[j][z] = 0;

			cout << arr[j][z];
			if (z != n) cout << " ";
		}

		if (j != n) cout << "\n";
	}

	return 0;
}