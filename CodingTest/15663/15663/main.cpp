#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];
int items[10];

bool visit[10][10000];

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i];
			if (i != m - 1) cout << " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int item = items[i];
			bool canSkip = true;

			arr[cnt] = item;

			for (int j = 0; j <= cnt; j++)
			{
				if (visit[j][arr[j]] == false)
				{
					canSkip = false;
					break;
				}
			}

			if (canSkip == true) continue;

			visit[cnt][item] = true;
			dfs(cnt + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i];
	}

	sort(items, items + n);

	dfs(0);
	
	return 0;
}