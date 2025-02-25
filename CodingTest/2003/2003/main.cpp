#include <iostream>
using namespace std;

const int maxSize = 10000;
int arr[maxSize];

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int startIndex = -1;
	int endIndex = -1;
	
	int sum = 0;
	int result = 0;

	while (startIndex < n)
	{
		if (sum < m && endIndex < n - 1) // �������� m���� ���� ���
		{
			endIndex++;
			sum += arr[endIndex];
		}
		else // �������� m�� ���ų� �� ū ���
		{
			startIndex++;
			sum -= arr[startIndex];
		}

		if (sum == m)
		{
			result++;
		}
	}

	cout << result;
	return 0;
}