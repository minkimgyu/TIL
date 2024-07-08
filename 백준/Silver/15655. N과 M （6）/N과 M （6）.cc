#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

bool visit[100001];
int arr[10];
int items[10];

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
			if (cnt > 0 && item <= arr[cnt - 1]) continue;

			if (visit[item] == false)
			{
				visit[item] = true;
				arr[cnt] = item;
				dfs(cnt + 1);
				visit[item] = false;
			}
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