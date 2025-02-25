#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;
int arr[maxSize];

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

	int n, m;
	cin >> n >> m;

	fill(arr, arr + n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int type, a, b;
		cin >> type >> a >> b;

		if (type == 0)
		{
			uni(a, b);
		}
		else
		{
			int uParent = find(a);
			int vParent = find(b);

			if (uParent == vParent) cout << "YES";
			else cout << "NO";

			if (i != m - 1) cout << '\n';
		}
	}

	return 0;
}