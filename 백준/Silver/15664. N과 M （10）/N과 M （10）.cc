#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxSize = 9;

int arr[maxSize];
int inputArr[maxSize];
bool visit[maxSize];

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
			if (count > 0 && arr[count - 1] > inputArr[i]) continue;
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