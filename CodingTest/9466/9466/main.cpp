#include <iostream>
using namespace std;

int visitCount = 0;

int nextVisits[100001];
int currentIndexes[100001];

bool visitAlready[100001];

void dfs(int* arr, int nextItem, int loopIndex)
{
	if (visitAlready[nextItem] == true) return; // �̹� �湮�ؼ� ����Ŭ�� �������� �ʴ� ���� Ȯ���� ��� ����

	if (nextVisits[nextItem] != 0) // ����Ŭ�� ���Ƽ� �ٽ� ������ ���
	{
		visitCount = loopIndex - currentIndexes[nextItem];
		return;
	}

	nextVisits[nextItem] = arr[nextItem];
	currentIndexes[nextItem] = loopIndex;

	dfs(arr, arr[nextItem], loopIndex + 1);

	visitAlready[nextItem] = true; // �湮�� �迭�� visit ǥ�� ���ֱ�
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