#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	queue<int> result;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) q.push(i);

	while (q.empty() == false)
	{
		for (int i = 1; i <= k - 1; i++)
		{
			int frontItem = q.front(); q.pop();
			q.push(frontItem);
		}

		int popItem = q.front(); q.pop();
		result.push(popItem);
	}

	cout << "<";

	int resultSize = result.size();
	for(int i = 0; i < resultSize; i++)
	{
		int item = result.front(); result.pop();
		if(i == resultSize - 1) cout << item;
		else cout << item << ", ";
	}

	cout << ">";
	return 0;
}