#include <iostream>
#include <queue>
using namespace std;

// ���� �� ���� ���ļ� ����� ���̴� ���� ��ǥ!
// ���� �� 2���� ���� �����ְ� �ٽ� �ִ´�.


// 1,000,000 
// 10,000

// 10,000,000,000 --> �ִ� 100���̱� ������ long long int�� sum ������ �������ش�.

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap;
		long long int sum = 0;

		int cnt;
		cin >> cnt;
		
		for (int j = 0; j < cnt; j++)
		{
			int item;
			cin >> item;
			minHeap.push(item);
		}

		while (minHeap.size() > 1) // 1�̸� pass
		{
			long long int top = minHeap.top();
			minHeap.pop();

			long long int second = minHeap.top();
			minHeap.pop();

			long long int addCost = top + second;
			sum += addCost;
			minHeap.push(addCost);
		}

		cout << sum;
		if (i != t - 1) cout << '\n';
	}

	return 0;
}