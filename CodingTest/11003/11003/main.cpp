#include <iostream>
#include <queue>
using namespace std;

int n, l;
int arr[5000000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	deque<pair<int, int>> deque;
	int minItem = 1000000001;

	int frontIndex = -1;

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (l <= i)
		{
			frontIndex++;
			pair<int, int> frontItem = deque.front();
			if (frontItem.first == frontIndex) deque.pop_front();
		}

		while (deque.empty() == false && deque.back().second > arr[i]) deque.pop_back();

		deque.push_back({ i, arr[i] });

		cout << deque.front().second;
		if (i != n - 1) cout << " ";
	}

	return 0;
}