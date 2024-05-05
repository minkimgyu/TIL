#include <iostream>
using namespace std;

int main()
{
	const int cnt = 7;

	int sum = 0;
	int min = 100;

	for (int i = 0; i < cnt; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp % 2 == 0) continue;

		sum += tmp;
		if (tmp < min) min = tmp;
	}
	
	if (sum == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sum;
		cout << '\n';
		cout << min;
	}

	return 0;
}