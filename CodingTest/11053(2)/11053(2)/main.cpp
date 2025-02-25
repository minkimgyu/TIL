#include <iostream>
#include <algorithm>
using namespace std;

int n;

const int maxArrSize = 1000;
int arr[maxArrSize];
int dp[maxArrSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = 1; // 1�� �ʱ�ȭ --> �ڱ� �ڽ��� ���� �������̹Ƿ� �׻� ���̴� 1���� �����Ѵ�.
	}

	int result = 1; // ���� ���̽�: n�� 1�� ��쿡 1�� ����ؾ��Ѵ�.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j]) // �ռ� �� �� ���� ������ �����Ѵ�.
			{
				dp[i] = max(dp[i], dp[j] + 1);
				result = max(dp[i], result);
			}
		}
	}

	cout << result;
	return 0;
}