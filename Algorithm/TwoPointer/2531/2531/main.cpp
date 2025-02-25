#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[30000 + 3005];
int visit[3000 + 5];

bool NowOverlap()
{
	for (int i = 0; i < 3000 + 5; i++)
	{
		if (visit[i] > 1)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < k - 1; i++)
	{
		arr[n + i] = arr[i];
	}

	queue<int> qu;
	int result = 0;

	for (int i = 0; i < k; i++)
	{
		qu.push(arr[i]);
		visit[arr[i]] += 1;

		if (NowOverlap() == false)
		{
			if(visit[c] == false) 
		}
	}

	for (int i = k; i < n + k; i++)
	{
		int front = qu.front();
		visit[front] -= 1;
		qu.pop();

		qu.push(arr[i]);

		if (NowOverlap() == false)
		{

		}
	}

	return 0;
}