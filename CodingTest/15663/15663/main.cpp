#include <iostream>
#include <algorithm>
<<<<<<< HEAD
using namespace std;

int n, m;

const int maxSize = 15;
int arr[maxSize];
int inputArr[maxSize];

bool visit[maxSize];

void dfs(int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
		{
			// ���⼭ �迭�� map�� �ֱ�
			cout << arr[i];
			if (i != m - 1) cout << " ";
		}

=======
#include <vector>
using namespace std;

int n, m;
int arr[10];
int items[10];

bool visit[10][10000];

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i];
			if (i != m - 1) cout << " ";
		}
>>>>>>> origin/main
		cout << '\n';
	}
	else
	{
<<<<<<< HEAD

		int item = 0; 
		// �̷� ������ �ٷ� ���� ���� ���� �� �ִ� ���� ���� ������ �� ���� ��
		// �̷��� �ϸ� �� �ٸ� 9�� ������ ���� ������ �� ����
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == true) continue;
			if (item == inputArr[i]) continue;

			visit[i] = true;
			item = arr[count] = inputArr[i];
			dfs(count + 1);
			visit[i] = false;
=======
		for (int i = 0; i < n; i++)
		{
			int item = items[i];
			bool canSkip = true;

			arr[cnt] = item;

			for (int j = 0; j <= cnt; j++)
			{
				if (visit[j][arr[j]] == false)
				{
					canSkip = false;
					break;
				}
			}

			if (canSkip == true) continue;

			visit[cnt][item] = true;
			dfs(cnt + 1);
>>>>>>> origin/main
		}
	}
}

int main()
{
<<<<<<< HEAD
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> inputArr[i];
	}

	sort(inputArr, inputArr + n);
	dfs(0);

=======
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> items[i];
	}

	sort(items, items + n);

	dfs(0);
	
>>>>>>> origin/main
	return 0;
}