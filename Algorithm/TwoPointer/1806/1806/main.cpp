#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int en = 0;
	int tot = arr[0];
	int result = 100000 + 5;

	//sort(arr, arr + n);

	for (int st = 0; st < n; st++)
	{
		while (en < n && tot < s)
		{
			en++;

			if (en == n) break;
			tot += arr[en];
		}
		if (en == n) break;

		result = min(result, en - st + 1);
		tot -= arr[st];
	}

	if (result == 100000 + 5) cout << 0;
	else cout << result;

	return 0;
}