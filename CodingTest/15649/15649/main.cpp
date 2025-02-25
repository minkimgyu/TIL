#include <iostream>
using namespace std;

int arr[10]{ 0, };
bool visit[10]{ false, };

void dfs(int cnt, int n, int m)
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
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == false)
			{
				visit[i] = true;
				arr[cnt] = i;
				dfs(cnt + 1, n, m);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	dfs(0, n, m);
	return 0;
}