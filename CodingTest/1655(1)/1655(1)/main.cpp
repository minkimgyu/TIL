#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
중간 값 구하기 알고리즘
1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minPQ;
	priority_queue<int, vector<int>, less<int>> maxPQ;

	// maxPQ의 크기는 minPQ와 같거나 하나 더 크다
	// maxPQ의 top은 minPQ의 top보다 작거나 같다.

	// 위 두 조건이 맞지 않으면 top을 서로 바꿔준다.

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