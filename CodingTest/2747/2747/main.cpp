#include <iostream>
using namespace std;

// ������ ���� ���α׷��� ����
// �Ǻ���ġ ������ �̿��Ѵ�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	int* arr = new int[n + 1] { 0 };

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	cout << arr[n];

	return 0;
}