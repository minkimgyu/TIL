#include <iostream>
using namespace std;

bool IsPrime(int item)
{
	if (item == 1) return false;

	for (int j = 2; j * j <= item; j++)
	{
		if (item % j == 0) return false;
	}

	return true;
}

int main()
{
	int n;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		bool isPrime = IsPrime(item);
		if (isPrime == true) result++;
	}

	cout << result;
	return 0;
}