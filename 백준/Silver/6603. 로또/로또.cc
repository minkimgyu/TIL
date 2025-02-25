#include <iostream>
using namespace std;

int t, k;

int pickCount = 6;
int arr[50];
int valueArr[50];
bool visit[50];

void dfs(int first, int count)
{
	if (count == pickCount)
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i];
			if (i != count - 1) cout << " ";
		}

		cout << '\n';
	}
	else
	{
		for (int i = 0; i < first; i++)
		{
			if (visit[valueArr[i]] == true) continue;
			if (count > 0 && arr[count - 1] >= valueArr[i]) continue;

			visit[valueArr[i]] = true;
			arr[count] = valueArr[i];
			dfs(first, count + 1);
			visit[valueArr[i]] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		int first;
		cin >> first;
		if (first == 0) break;

		for (int i = 0; i < first; i++)
		{
			cin >> valueArr[i];
		}

		dfs(first, 0);
		cout << '\n';
	}

	return 0;
}