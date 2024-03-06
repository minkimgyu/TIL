#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int* bucket = new int[n];

	for (int i = 1; i <= n; i++) bucket[i - 1] = i;

	for (int j = 0; j < m; j++)
	{
		int a, b;
		cin >> a >> b;

		int tmp;
		tmp = bucket[a - 1];
		bucket[a - 1] = bucket[b - 1];
		bucket[b - 1] = tmp;
	}

	for (int i = 0; i < n; i++)
	{
		if(i == n - 1) cout << bucket[i];
		else cout << bucket[i] << " ";
	}

	return 0;
}