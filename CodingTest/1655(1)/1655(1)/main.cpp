#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
�߰� �� ���ϱ� �˰���
1. �ִ� ���� ũ��� �ּ� ���� ũ��� ���ų�, �ϳ� �� ũ��.
2. �ִ� ���� �ִ� ���Ҵ� �ּ� ���� �ּ� ���Һ��� �۰ų� ����.
�̶� �˰��� ���� �ʴٸ� �ִ� ��, �ּ� ���� ���� ���� ���� swap���ش�.
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minPQ;
	priority_queue<int, vector<int>, less<int>> maxPQ;

	// maxPQ�� ũ��� minPQ�� ���ų� �ϳ� �� ũ��
	// maxPQ�� top�� minPQ�� top���� �۰ų� ����.

	// �� �� ������ ���� ������ top�� ���� �ٲ��ش�.

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		if (maxPQ.size() == minPQ.size())
		{
			maxPQ.push(item);
		}
		else
		{
			minPQ.push(item);
		}
		
		if (minPQ.empty() == false && maxPQ.empty() == false)
		{
			if (minPQ.top() < maxPQ.top())
			{
				int minPQTop = minPQ.top();
				int maxPQTop = maxPQ.top();

				maxPQ.pop();
				minPQ.pop();

				maxPQ.push(minPQTop);
				minPQ.push(maxPQTop);
			}
		}
		
		cout << maxPQ.top();
		if (i != n - 1) cout << '\n';
	}

	return 0;
}