#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; // n�� ���� ����, m�� ��緹�� ����
	cin >> n >> m;

	int left = 0;
	int right = 0;

	// �ð� ���⵵ : n + log(n) * n
	// �־��� ��� : n + n * n

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		right += arr[i];
		
		if (i == 0) left = arr[i];
		else { if (arr[i] > left) left = arr[i]; }
	}

	// left�� ��緹�� ũ�� �� ���� ���� ��
	// right�� ��緹�� ũ�� �� ���� ū ��

	while (left <= right) // left ���� right ������ ū ��� ���� ã�� ���� --> count == m�� ���͵� �߰� ���� ������ �ذ� �ƴ� �� �ֱ� ������ ��� ������������
	{
		int mid = (int)((left + right) / 2);

		int sum = 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + arr[i] > mid)
			{
				sum = 0;
				count++;
			}
			sum += arr[i];
		}

		if (sum > 0) count++; // �������� ���� sum ���� �����Ѵٸ� count ���� 1 �÷��ش�.

		if (count > m) // ���� ��緹�� ������ �־��� ������ ū ��� --> �߰� ���� �۴ٴ� �ǹ̸� ����
		{
			left = mid + 1;
		}
		else // �ݴ��� ��� right�� -1 ���ش�.
		{
			right = mid - 1;
		}
	}
	
	cout << left;

	return 0;
}