#include <iostream>
using namespace std;

const int maxSize = 40000;

// 최대공약수
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

		if (m == x) x = 0; // 예를 들어 m이 10이고 x가 10인 경우는 존재할 수 없다. --> 0으로 처리해줘야함
		if (n == y) y = 0;

		bool canFind = false;

		int lcm = LCM(m, n);
		for (int i = x; i <= lcm; i += m)
		{
			if (i == 0) continue; // 필요함!
			if (i % n == y) // m이나 n으로 나눠서 x나 y가 나오는 경우
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