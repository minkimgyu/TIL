#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	queue<int> addQ;
	int tmp;

	cin >> tmp;

	for (int i = 1; i <= tmp; i++)
	{
		q.push(i);
	}

	int tmpCount = 1;

	while (!q.empty())
	{
		if (tmpCount % 2 != 0) // 짝수가 아닌 경우
		{
			int tmpValue = q.front();
			q.pop();
			addQ.push(tmpValue);
		}
		else
		{
			int tmpValue = q.front();
			q.pop();
			q.push(tmpValue);
		}

		tmpCount++;
	}

	int addQSize = addQ.size();

	for (int i = 0; i < addQSize; i++)
	{
		int tmpValue = addQ.front();

		if (i != addQSize - 1)
			cout << tmpValue << " ";
		else
			cout << tmpValue;
		addQ.pop();
	}

	return 0;
}