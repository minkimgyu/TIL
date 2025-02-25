#include <iostream>
#include <algorithm>
using namespace std;

const int maxSize = 300 + 5;
int arr[maxSize];

int dp[3][maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[1][1] = arr[1]; // ù ��� ���� ��� �ֱ� - 1�� ����
	dp[1][2] = arr[2]; // ù ��� ���� ��� �ֱ� - 2�� ����

	for (int i = 1; i <= n; i++)
	{
		dp[2][i + 1] = max(dp[2][i + 1], dp[1][i] + arr[i + 1]); // 1�� ����


		dp[1][i + 2] = max(dp[1][i + 2], dp[1][i] + arr[i + 2]); // 2�� ����

		dp[1][i + 2] = max(dp[1][i + 2], dp[2][i] + arr[i + 2]); // �����ؼ� �� �� ���� ��� 2�� ����
	}

	cout << max(dp[1][n], dp[2][n]); // 1���� �Ǵ� 2�������� ���� ��

	return 0;
}