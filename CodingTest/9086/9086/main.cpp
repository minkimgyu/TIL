#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 1000;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char* arr = new char[count]; // ���� �Ҵ� �� �����ϴ� ������� ����
		cin >> arr;

		int start = 0;
		int end = 0;

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == '\0')
			{
				end = i - 1; // ������ ������ ���, �� �ձ��� Ȯ���ϱ�
				break;
			}
		}

		cout << arr[start] << arr[end] << '\n';
		delete[] arr;
	}

	return 0;
}