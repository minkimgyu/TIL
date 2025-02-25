#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;

		int sum = 0;
		priority_queue<int, vector<int>, greater<int>> pQ;

		for (int j = 0; j < k; j++)
		{
			int item;
			cin >> item;
			pQ.push(item);
		}

		while (pQ.size() > 1)
		{
			int front = pQ.top();
			pQ.pop();

			int second = pQ.top();
			pQ.pop();

			int mix = front + second;
			sum += mix;

			pQ.push(mix);
		}
		
		cout << sum;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}