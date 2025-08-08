#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxSize = 100000 + 5;
pair<int, int> arr[maxSize];

//bool compare(pair<int, int> a, pair<int, int> b)
//{
//	if (a.second == b.second) return a.first < b.first;
//	return a.second < b.second;
//}

priority_queue<int, vector<int>, greater<int>> pQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + n);

	int result = 1;
	pQ.push(arr[0].second);

	int idx = 1;
	for (int i = 1; i < n; i++)
	{
		if (pQ.top() > arr[i].first)
		{
			result++;
			pQ.push(arr[i].second);
		}
		else
		{
			pQ.pop();
			pQ.push(arr[i].second);
		}
	}

	cout << result;

	return 0;
}