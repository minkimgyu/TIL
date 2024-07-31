#include <iostream>
using namespace std;

int visitCount = 0;
int loopCount = 100001;

int nextVisits[100001];
int currentIndexes[100001];

bool visitAlready[100001];

void dfs(int* arr, bool* visit, int nextItem, int loopIndex)
{
	if (visitAlready[nextItem] == true) return;

	if (nextVisits[nextItem] != 0) // 사이클을 돌아서 다시 만나는 경우
	{
		visitCount = loopIndex - currentIndexes[nextItem];
		loopCount = currentIndexes[nextItem];
		return;
	}

	if (visit[nextItem] == true) return;  // 이전에 사이클을 찾은 변수라면 리턴

	nextVisits[nextItem] = arr[nextItem];
	currentIndexes[nextItem] = loopIndex;
	visit[nextItem] = true;

	dfs(arr, visit, arr[nextItem], loopIndex + 1);

	if (loopIndex < loopCount)
	{
		visit[nextItem] = false;
	}

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
		bool* visit = new bool[n + 1];

		for (int j = 1; j <= n; j++)
		{
			int item;
			cin >> item;

			arr[j] = item;
			visit[j] = false;

			nextVisits[j] = 0;
			currentIndexes[j] = 0;
			visitAlready[j] = false;
		}

		int resultSum = 0;
		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == true) continue;

			dfs(arr, visit, j, 0);

			resultSum += visitCount;
			visitCount = 0;
			loopCount = 100001;
		}

		cout << n - resultSum;
		if (i != t - 1) cout << '\n';

		delete[] arr;
	}

	return 0;
}