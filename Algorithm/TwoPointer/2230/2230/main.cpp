#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100001;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int result = 2000000000 + 5;

	int en = 0;
	for (int st = 0; st < n; st++)
	{
		while (en < n && arr[en] - arr[st] < m) en++;
		if (en == n) break;
		result = min(result, arr[en] - arr[st]);
	}

	cout << result;
	return 0;
}