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

		// 첫번째 바구니는 0번째 인덱스이므로 줄여줘야함
		a -= 1;
		b -= 1;

		// 맨 앞과 뒤를 서로 뒤집어줌
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