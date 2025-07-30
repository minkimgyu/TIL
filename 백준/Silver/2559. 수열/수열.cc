#include <iostream>
#include <queue>
using namespace std;

const int maxSize = 100000 + 5;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int total = 0;
	int result = -100 * 100000 - 5;
	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		if (q.size() < k)
		{
			q.push(arr[i]);
			total += arr[i];
		}
		else if(q.size() == k)
		{
			total -= q.front();
			q.pop();

			q.push(arr[i]);
			total += arr[i];
		}

		if (q.size() == k) result = max(result, total);
	}

	cout << result;
	return 0;
}