#include <iostream>
using namespace std;

int n, m;
int arr[10]{ 0, };
bool visit[10]{ false, };

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
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == false)
			{
				if (cnt > 0 && i < arr[cnt - 1]) continue;

				visit[i] = true;
				arr[cnt] = i;

				dfs(cnt + 1);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(0);
	return 0;
}