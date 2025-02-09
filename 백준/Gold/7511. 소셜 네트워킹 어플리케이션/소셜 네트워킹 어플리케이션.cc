#include <iostream>
#include <vector>
using namespace std;

int arr[1000000 + 5];

int find(int x)
{
	if (arr[x] < 0) return x;
	return x = find(arr[x]);
}

bool uni(int u, int v)
{
	int uParent = find(u);
	int vParent = find(v);

	if (uParent == vParent) return false;

	arr[vParent] = uParent;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		int n, k;
		cin >> n >> k;

		fill(arr, arr + n + 1, -1);

		for (int j = 0; j < k; j++)
		{
			int a, b;
			cin >> a >> b;

			uni(a, b);
		}

		int m;
		cin >> m;

		vector<int> result;

		for (int k = 0; k < m; k++)
		{
			int u, v;
			cin >> u >> v;

			int uParent = find(u);
			int vParent = find(v);

			if (uParent == vParent) result.push_back(1);
			else result.push_back(0);
		}

		cout << "Scenario " << i << ":" << '\n';
		int resultSize = result.size();
		for (int i = 0; i < resultSize; i++)
		{
			cout << result[i] << '\n';
		}

		if(i != t) cout << '\n';
	}

	return 0;
}