#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int arr[10];
int items[10];
bool visit[10001];

vector<vector<int>> history;

void dfs(int cnt)
{
	if (cnt == m)
	{
		bool canPass = true;

		for (int i = 0; i < history.size(); i++)
		{
			vector<int> item = history[i];
			canPass = true;

			for (int j = 0; j < item.size(); j++)
			{
				if (arr[j] != item[j])
				{
					canPass = false;
					break;
				}
			}

			if (canPass == true) return;
		}

		vector<int> item;
		for (int i = 0; i < m; i++)
		{
			item.push_back(arr[i]);

			cout << arr[i];
			if (i != m - 1) cout << " ";
		}
		cout << '\n';

		history.push_back(item);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int item = items[i];
			arr[cnt] = item;
			dfs(cnt + 1);
		}
	}
}

int main()
{
/*	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i];
	}

	sort(items, items + n);

	dfs(0)*/;

	int result = 0;

	int n = 5;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		result += item * item;
	}

	cout << result % 10;

	return 0;
}