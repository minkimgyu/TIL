#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int first = 0;
	int firstItem = 0;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		if (i == 1)
		{
			first = num;
			firstItem = first;
		}

		pQ.push({ num, i });
	}

	while (pQ.top().second != 1)
	{
		pair<int, int> topItem = pQ.top();

		topItem.first -= 1;
		firstItem += 1;
		pQ.pop();

		pQ.push(topItem);
		pQ.push({ firstItem, 1 });
	}

	cout << pQ.top().first - first;
	return 0;
}