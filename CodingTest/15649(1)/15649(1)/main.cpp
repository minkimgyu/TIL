#include <iostream>
using namespace std;

int n, m;
const int maxM = 9;

int arr[maxM];
bool visit[maxM];

void dfs(int count)
{
	if (count == m)
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i];
			if (i != m - 1)
			{
				cout << " ";
			}
		}

		cout << '\n';
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == true) continue;

			visit[i] = true;
			arr[count] = i;
			count++;
			dfs(count);
			count--;
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