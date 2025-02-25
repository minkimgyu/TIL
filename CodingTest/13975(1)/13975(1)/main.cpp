#include <iostream>
#include <queue>
using namespace std;

// 작은 것 부터 합쳐서 비용을 줄이는 것이 목표!
// 작은 것 2개를 빼서 더해주고 다시 넣는다.


// 1,000,000 
// 10,000

// 10,000,000,000 --> 최대 100억이기 때문에 long long int로 sum 변수를 선언해준다.

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

		while (minHeap.size() > 1) // 1이면 pass
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