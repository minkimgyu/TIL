#include <iostream>
using namespace std;

int n, m;
bool visit[9];
int arr[9];

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
			if (visit[i] == true) continue;
			visit[i] = true;

			arr[count] = i;
			dfs(count + 1);

			visit[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	dfs(0);
	return 0;
}