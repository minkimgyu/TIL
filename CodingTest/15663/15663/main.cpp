#include <iostream>
#include <algorithm>
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
			// 여기서 배열을 map에 넣기
			cout << arr[i];
			if (i != m - 1) cout << " ";
		}

		cout << '\n';
	}
	else
	{

		int item = 0; 
		// 이런 식으로 바로 직전 값과 비교할 수 있는 값을 만들어서 실행할 수 없게 함
		// 이렇게 하면 또 다른 9가 나오는 것을 방지할 수 있음
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == true) continue;
			if (item == inputArr[i]) continue;

			visit[i] = true;
			item = arr[count] = inputArr[i];
			dfs(count + 1);
			visit[i] = false;
		}
	}
}

int main()
{
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

	return 0;
}