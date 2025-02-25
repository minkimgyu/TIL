#include <iostream>
#include <algorithm>
using namespace std;

int dp[500][500];
int arr[500][500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> arr[i][j];
		}
	}

	int maxWay = 0;


	// n�� 1�� ��� ���� ù��° �ε����� �������ִ� �ڵ带 �߰������ �Ѵ�.
	if (n == 1)
	{
		cout << arr[0][0];
		return 0;
	}

	dp[0][0] = arr[0][0];

	// �� �������� ���� �� ��
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (max(dp[i + 1][j], arr[i + 1][j] + dp[i][j]) == arr[i + 1][j] + dp[i][j])
			{
				dp[i + 1][j] = arr[i + 1][j] + dp[i][j];

				if (maxWay < dp[i + 1][j]) maxWay = dp[i + 1][j];
			}

			if (max(dp[i + 1][j + 1], arr[i + 1][j + 1] + dp[i][j]) == arr[i + 1][j + 1] + dp[i][j])
			{
				dp[i + 1][j + 1] = arr[i + 1][j + 1] + dp[i][j];

				if (maxWay < dp[i + 1][j + 1]) maxWay = dp[i + 1][j + 1];
			}
		}
	}

	cout << maxWay;
	return 0;
}