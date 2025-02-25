#include <iostream>
using namespace std;

int n, m;
const int maxSize = 9;
int arr[maxSize];

void dfs(int count)
{
	if(count == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i];
			if (i != m - 1)
			{
				cout << " ";
			}
		}

		cout << '\n';
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (count >= 1 && arr[count - 1] > i) continue;

			arr[count] = i;
			dfs(count + 1);
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