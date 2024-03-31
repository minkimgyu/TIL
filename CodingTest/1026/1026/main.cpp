#include <iostream>
#include <algorithm>
using namespace std;

bool ACompare(int a, int b)
{
	return a < b;
}

bool BCompare(int a, int b)
{
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int* d = new int[101]{ -1 };

	int n;
	cin >> n;

	int* a = new int[n];
	int* b = new int[n];

	int* c = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		b[i] = tmp; // 원본 값
		c[i] = tmp;
	}

	sort(a, a + n, BCompare);
	sort(c, c + n, ACompare);

	for (int i = 0; i < n; i++)
	{
		d[c[i]] = i;
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[d[c[i]]];
	}

	cout << sum;

	return 0;
}