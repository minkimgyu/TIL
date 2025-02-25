#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char valueArr[15];
char arr[15];
bool visit[15];
int aeiouCount = 0;

bool compare(char a, char b)
{
	return a < b;
}

void dfs(int count)
{
	if (count == l)
	{
		if (aeiouCount == 0) return;
		if (count - aeiouCount < 2) return; // ��ü ������ ���� ������ ���� 2���� ������ ����
		// ex) 4 - 3 --> return!


		// ���� ������ �������ѵ� ���� 2�� �̻� ������ ���� ���Ѵٸ� ����

		for (int i = 0; i < count; i++)
		{
			cout << arr[i];
			if (i == l - 1) cout << " ";
		}
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < c; i++)
		{
			if (count > 0 && arr[count - 1] >= valueArr[i]) continue;
			if (visit[i] == true) continue;

			visit[i] = true;

			if (valueArr[i] == 'a' || valueArr[i] == 'e' || valueArr[i] == 'i' || valueArr[i] == 'o' || valueArr[i] == 'u')
			{
				aeiouCount++;
			}

			arr[count] = valueArr[i];
			dfs(count + 1);
			visit[i] = false;

			if (valueArr[i] == 'a' || valueArr[i] == 'e' || valueArr[i] == 'i' || valueArr[i] == 'o' || valueArr[i] == 'u')
			{
				aeiouCount--;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> valueArr[i];
	}

	sort(valueArr, valueArr + c, compare);

	dfs(0);

	return 0;
}