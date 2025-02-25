#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> items;
int arr[10];
int n, m;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i];
			if (i != m - 1) cout << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 0; i < items.size(); i++)
		{
			int item = items[i];
			if (cnt > 0 && arr[cnt - 1] > item) continue;

			arr[cnt] = items[i];
			dfs(cnt + 1);
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