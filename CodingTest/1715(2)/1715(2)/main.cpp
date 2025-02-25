#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> minPQ;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		minPQ.push(item);
	}

	int result = 0;

	while (minPQ.size() > 1)
	{
		int one = minPQ.top();
		minPQ.pop();

		int second = minPQ.top();
		minPQ.pop();

		int sum = one + second;
		result += sum;

		minPQ.push(sum);
	}

	cout << result;
	return 0;
}