#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool visit[9];
int inputArr[9];

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
		int item = -1;
		for (int i = 0; i < n; i++)
		{
			if (item == inputArr[i]) continue;
			if (visit[i] == true) continue;
			visit[i] = true;

			item = arr[count] = inputArr[i];
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
	for (int i = 0; i < n; i++)
	{
		cin >> inputArr[i];
	}

	sort(inputArr, inputArr + n);
	dfs(0);
	return 0;
}