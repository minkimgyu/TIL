#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> pQ;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int count;
		cin >> count;

		if (count == 0)
		{
			if (pQ.empty() == false)
			{
				int item = pQ.top(); pQ.pop();
				cout << item;
			}
			else
			{
				cout << -1;
			}

			if(i != n - 1) cout << '\n';
		}
		else
		{
			for (int j = 0; j < count; j++)
			{
				int item;
				cin >> item;

				pQ.push(item);
			}
		}
	}

	return 0;
}