#include <iostream>
using namespace std;

const int maxSize = 40000;

// �ִ�����
int GCD(int a, int b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return a / GCD(a, b) * b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		if (m == x) x = 0; // ���� ��� m�� 10�̰� x�� 10�� ���� ������ �� ����. --> 0���� ó���������
		if (n == y) y = 0;

		bool canFind = false;

		int lcm = LCM(m, n);
		for (int i = x; i <= lcm; i += m)
		{
			if (i == 0) continue; // �ʿ���!
			if (i % n == y) // m�̳� n���� ������ x�� y�� ������ ���
			{
				canFind = true;
				cout << i;
				break;
			}
		}

		if (canFind == false) cout << -1;
		if(i != t - 1) cout << '\n';
	}

	return 0;
}