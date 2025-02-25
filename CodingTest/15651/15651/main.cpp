#include <iostream>
using namespace std;

int n, m;
int arr[10];

void dfs(int count)
{
	if (count == m)
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
		for (int i = 1; i <= n; i++)
		{
			arr[count] = i;
			dfs(count + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(0);
	return 0;
}