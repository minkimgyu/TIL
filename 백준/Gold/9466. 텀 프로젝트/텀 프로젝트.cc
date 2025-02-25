#include <iostream>
using namespace std;

int visitCount = 0;

int nextVisits[100001];
int currentIndexes[100001];

bool visitAlready[100001];

void dfs(int* arr, int nextItem, int loopIndex)
{
	if (visitAlready[nextItem] == true) return; // 이미 방문해서 사이클이 형성되지 않는 것을 확인한 경우 리턴

	if (nextVisits[nextItem] != 0) // 사이클을 돌아서 다시 만나는 경우
	{
		visitCount = loopIndex - currentIndexes[nextItem];
		return;
	}

	nextVisits[nextItem] = arr[nextItem];
	currentIndexes[nextItem] = loopIndex;

	dfs(arr, arr[nextItem], loopIndex + 1);

	visitAlready[nextItem] = true;
	nextVisits[nextItem] = 0;
	currentIndexes[nextItem] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		int* arr = new int[n + 1];

		for (int j = 1; j <= n; j++)
		{
			int item;
			cin >> item;

			arr[j] = item;

			nextVisits[j] = 0;
			currentIndexes[j] = 0;
			visitAlready[j] = false;
		}

		int resultSum = 0;
		for (int j = 1; j <= n; j++)
		{
			dfs(arr, j, 0);

			resultSum += visitCount;
			visitCount = 0;
		}

		cout << n - resultSum;
		if (i != t - 1) cout << '\n';

		delete[] arr;
	}

	return 0;
}