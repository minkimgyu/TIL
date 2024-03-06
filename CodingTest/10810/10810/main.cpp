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

	for (int i = 0; i < n; i++) bucket[i] = 0; // 0으로 초기화

	for (int a = 0; a < m; a++)
	{
		int i, j, k;
		cin >> i >> j >> k;

		for (int b = i - 1; b <= j - 1; b++) // 0번째 인덱스가 1번 바구니이므로 잘 생각해보기
		{
			bucket[b] = k;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if(i == n - 1) cout << bucket[i];
		else cout << bucket[i] << " ";
	}

	return 0;
}