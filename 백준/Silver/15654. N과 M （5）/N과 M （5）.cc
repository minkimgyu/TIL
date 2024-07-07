#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
bool visit[10000];

vector<int> items;

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
		for (int i = 0; i < items.size(); i++)
		{
			int item = items[i];
			if (visit[item] == true) continue;

			visit[item] = true;
			arr[cnt] = item;
			dfs(cnt + 1);
			visit[item] = false;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		items.push_back(item);
	}

	sort(items.begin(), items.end());
	dfs(0);

	return 0;
}