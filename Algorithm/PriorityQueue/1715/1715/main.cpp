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

	priority_queue<int, vector<int>, greater<int>> pQ;

	int n;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		pQ.push(item);
	}

	while (pQ.size() > 1)
	{
		int itemA = pQ.top();
		pQ.pop();

		int itemB = pQ.top();
		pQ.pop();

		int item = itemA + itemB;
		result += item;
		pQ.push(item);
	}

	cout << result;
	return 0;
}