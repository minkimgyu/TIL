#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int* bucket = new int[n];

	for (int i = 0; i < n; i++) bucket[i] = i + 1;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		// ù��° �ٱ��ϴ� 0��° �ε����̹Ƿ� �ٿ������
		a -= 1;
		b -= 1;

		// �� �հ� �ڸ� ���� ��������
		int countToSwap = (b - a + 1) / 2;
		for (int j = 0; j < countToSwap; j++)
		{
			int tmp = bucket[a];
			bucket[a] = bucket[b];
			bucket[b] = tmp;

			a += 1;
			b -= 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if(i == n - 1) cout << bucket[i];
		else  cout << bucket[i] << " ";
	}

	delete[] bucket;

	return 0;
}