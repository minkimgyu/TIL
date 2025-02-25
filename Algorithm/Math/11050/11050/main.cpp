#include <iostream>
using namespace std;

int Factorial(int n)
{
	/*if (n == 1) return 1;
	return n * Factorial(n - 1);*/

	int result = 1;
	for (int i = 2; i <= n; i++) result *= i;
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 5 * 4 / 2 * 1
	// 5 * 4 * 3 * 2 * 1

	int n, k;
	cin >> n >> k;
	cout << Factorial(n) / (Factorial(n - k) * Factorial(k));

	return 0;
}