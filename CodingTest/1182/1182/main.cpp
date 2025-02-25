#include <iostream>
using namespace std;

int n, s;
int arr[20];
int valueArr[20];

bool visit[20];
int result = 0;

// 20 1000000
// 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999 99999

// �Է�����
// 5 0
// 0 0 0 0 0

// �̷� ������ ���� �� �ֱ� ������ ���� ���� ���� ��� ���� ������δ� ���װ� ����.
// ���� index�� arr�� �����Ͽ� �� �κ��� �ذ��Ѵ�.

void dfs(int count, int sum)
{
	if (count > 0 && sum == s)
	{
		result++;
	}
	if (count == n) return;

	/*for (int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';*/

	for (int i = 0; i < n; i++)
	{
		if (count > 0 && arr[count - 1] >= i) continue;
		if (visit[i] == true) continue;

		visit[i] = true;
		sum += valueArr[i];
		arr[count] = i;

		dfs(count + 1, sum);

		visit[i] = false;
		sum -= valueArr[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> valueArr[i];
	}

	dfs(0, 0);

	cout << result;
	return 0;
}