#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[7];
int outputs[7];

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << outputs[i];
			if (i != m - 1) cout << " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int item = arr[i];
			outputs[cnt] = item;
			dfs(cnt + 1);
		}
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	dfs(0);

	return 0;
}