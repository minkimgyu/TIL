#include <iostream>
using namespace std;

int n, m;
int arr[10];

void dfs(int cnt)
{
	if (m == cnt)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i];
			if (i != m) cout << " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (cnt > 0 && i < arr[cnt - 1]) continue;

			arr[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main()
{
	cin >> n >> m;

	dfs(0);

	return 0;
}