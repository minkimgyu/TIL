#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pQ;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		pQ.push(item);
	}

	int sum = 0;

	while (1)
	{
		if (pQ.size() == 1)
		{
			break;
		}
		else
		{
			int top1 = pQ.top();
			pQ.pop();

			int top2 = pQ.top();
			pQ.pop();

			int newItem = top1 + top2;
			sum += newItem;

			pQ.push(newItem);
		}
	}

	cout << sum;

	return 0;
}