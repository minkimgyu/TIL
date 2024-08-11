#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxSize = 8;
int arr[maxSize];
int inputArr[maxSize];

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
		int item = 0;
		for (int i = 0; i < n; i++)
		{
			if (item == inputArr[i]) continue;

			item = arr[count] = inputArr[i];
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
	for (int i = 0; i < n; i++)
	{
		cin >> inputArr[i];
	}
	sort(inputArr, inputArr + n);
	dfs(0);

	return 0;
}