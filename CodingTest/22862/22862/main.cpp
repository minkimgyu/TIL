#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

const int maxSize = 1000000;
int arr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int start = 0;
	int end = 0;
	int oddCount = 0;

	int result = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	if (n == 1)
	{
		if (arr[0] % 2 == 0) cout << 1;
		else cout << 0;

		return 0;
	}

	if (arr[end] % 2 != 0) oddCount++; // 0��° ���� Ȧ���̸� oddCount�� 1 �����ش�.
	else result = 1; // �ƴϸ� �κ� ������ ���̰� �ּ� 1 �̻��̶�� �Ҹ���

	while (start < n)
	{
		if (end < n - 1 && (oddCount == k && arr[end + 1] % 2 != 0) == false) // (end + 1)�� ���� oddCount ���� ���� �ִ� ���
		{
			end++;
			if (arr[end] % 2 != 0) oddCount++; // end�� ���� Ȧ����� �����ֱ�
		}
		else
		{
			if (arr[start] % 2 != 0) oddCount--; // start�� ���� Ȧ����� ���ֱ�
			start++;
		}

		if (oddCount <= k)
		{
			// Ȧ�� ������ k�� ������ ��츸 ������ش�.
			result = max(result, end - start + 1 - oddCount);
		}
	}

	cout << result;

	return 0;
}