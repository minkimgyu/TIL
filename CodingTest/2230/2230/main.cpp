#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

const int maxSize = 100000;
int arr[maxSize];

const int maxM = 2000000000;

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

	sort(arr, arr + n);

	int start = 0;
	int end = 0;

	int result = 0;
	int subtractResult = maxM;
	int answer = 0;

	while (start < n - 1)
	{
		if (result < m && end < n - 1) // ��� ���� ���ϴ� ������ �۰ų� end�� n - 1���� ���� ���
		{
			end++;
		}
		else // ������ ���
		{
			start++;
		}

		result = arr[end] - arr[start];

		int subtractPoint = result - m;
		if (subtractPoint >= 0 && subtractResult > subtractPoint) // result�� m�� ������ subtractPoint�� 0�� �� �� �����Ƿ� 0�� �����ؾ� �Ѵ�.
		{
			subtractResult = subtractPoint;
			answer = result;
		}
	}

	cout << answer;
	return 0;
}