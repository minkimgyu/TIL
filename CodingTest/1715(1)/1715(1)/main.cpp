#include <iostream>
#include <queue>
using namespace std;

// 엣지 케이스: 모든 숫자의 최대합은 100,000 * 1000 -> 100,000,000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pQ;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		pQ.push(item);
	}

	int result = 0;

	while (pQ.size() > 1) // 1인 경우에는 더 이상 합칠 수 없다.
	{
		int top = pQ.top();
		pQ.pop();

		int second = pQ.top();
		pQ.pop();

		int sum = top + second;
		result += sum;

		pQ.push(sum);
	}

	cout << result;
	return 0;
}