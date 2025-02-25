#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxSize = 50 + 5;
long long int states[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s, yAndN;
		cin >> s >> yAndN;

		//long long int item = 0;
		//long long int multi = 1;

		//for (int j = m - 1; j > -1; j--)
		//{
		//	if (yAndN[j] == 'Y') item += multi;
		//	multi *= 2;
		//}

		//states[i] = item;

		for (int j = m - 1; j > -1; j--)
		{
			states[i] = (states[i] << 1) | (yAndN[j] == 'Y'); // �� ĭ �о��ְ� (yAndN[j] == 'Y')�� ���̶�� �� ���� 1 �߰�
		}
	}

	int result = -1; // �ִ� 10������ ���� ����
	long long int storedState = 0;

	for (int i = 0; i < (1 << n); i++) // 2^n��ŭ ���� �ݺ� ex) m�� 5��� 00000, 00001, 00011... �̷������� �����
	{
		int pickCount = 0;
		long long int state = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				state |= states[j];
				pickCount++;
			}
		}

		if (storedState < state) // �� ���� ������ �� �ִ� ���
		{
			storedState = state;
			result = pickCount;
		}
		else if (storedState == state && result > pickCount) // ������ �� �ִ� �뷡 ������ ������ ������ ��Ÿ ������ ���� ���
		{
			result = pickCount;
		}
	}

	cout << result;
	return 0;
}