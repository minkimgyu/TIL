// 30 30 -> 60
// 40 50 -> 90
// 60 90 -> 150
// 
// 300!!

#include <queue>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

int t, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		priority_queue<long long int, vector<long long int>, greater<long long int>> pQ;
		long long int sum = 0;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int item;
			cin >> item;

			pQ.push(item);
		}

		for (int z = 0; z < k - 1; z++)
		{
			long long int top1 = pQ.top();
			pQ.pop();

			long long int top2 = pQ.top();
			pQ.pop();

			long long int newItem = top1 + top2;
			sum += newItem;

			pQ.push(newItem);
		}

		cout << sum;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}