#include <iostream>
#include <algorithm>
using namespace std;

const int dpSize = 1000;
int dp[1000];

int arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < dpSize; i++) dp[i] = 1;

	// A(i)�� ���� ���������� ���ӵǴ� ������ �����ϰ� �����غ���

	// ���� �迭�� {1}�̸� �䵵 1�� ���;��Ѵ�.
	int result = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] <= arr[j]) continue;

			// �ռ� dp������ ���� dp������ +1 �� ���� ������ ������ ������
			dp[i] = max(dp[i], dp[j] + 1);

			if (result < dp[i]) result = dp[i];
		}
	}

	cout << result;
	return 0;
}