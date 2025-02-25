#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int maxSize = 1000000;
vector<int> arr;
int inputArr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int inputNum;
		cin >> inputNum;

		arr.push_back(inputNum);
		inputArr[i] = inputNum;
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	for (int i = 0; i < n; i++)
	{
		vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), inputArr[i]);
		
		// start가 인덱스
		cout << iter - arr.begin();
		if (i != n - 1) cout << " ";
	}

	return 0;
}