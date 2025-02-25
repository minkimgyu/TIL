#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 100000 + 5;
const int maxSize = 100 + 5;

int arr[maxSize][maxSize];
int nxt[maxSize][maxSize];

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

		if (cost < arr[start][end]) // 갱신되는 경우
		{
			arr[start][end] = cost;
			nxt[start][end] = end;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (arr[j][i] + arr[i][k] < arr[j][k]) // 갱신되는 경우
				{
					nxt[j][k] = nxt[j][i]; // 주의!
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF) // 주의!
			{
				cout << 0;
			}
			else
			{
				cout << arr[i][j];
			}

			if (j != n) cout << " ";
		}

		cout << "\n";
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || arr[i][j] == INF) // 주의! 경로가 없으면 0 출력
			{
				cout << "0\n";
				continue;
			}

			int nxtIndex = i;
			int target = j;

			vector<int> indexes;
			while (nxtIndex != target)
			{
				indexes.push_back(nxtIndex);
				nxtIndex = nxt[nxtIndex][target];
			}

			indexes.push_back(target); // 끝 노드 넣기

			cout << indexes.size() << " ";

			for (int z = 0; z < indexes.size(); z++)
			{
				cout << indexes[z];
				if (z != indexes.size() - 1) cout << " ";
			}

			cout << "\n";
		}
	}

	return 0;
}