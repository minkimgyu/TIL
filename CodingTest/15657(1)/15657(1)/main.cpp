#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxSize = 9;
int arr[maxSize];
int inputArr[maxSize];

void dfs(int count) 
{
	if (count == m)
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
		for (int i = 0; i < n; i++)
		{
			if (count > 0 && arr[count - 1] > inputArr[i]) continue;

			arr[count] = inputArr[i];
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