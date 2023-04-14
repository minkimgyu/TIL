#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int count;

	cin >> count;

	for (int i = 1; i <= count; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		q.pop();

		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	cout << q.front();

	return 0;
}