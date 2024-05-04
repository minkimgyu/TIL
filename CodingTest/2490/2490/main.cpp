#include <iostream>
using namespace std;

int main()
{
	const int cnt = 3;
	char arr[cnt];

	for (int i = 0; i < cnt; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int sum = a + b + c + d;

		if (sum == 4) arr[i] = 'E';
		else if (sum == 3)arr[i] = 'A';
		else if (sum == 2)arr[i] = 'B';
		else if (sum == 1)arr[i] = 'C';
		else arr[i] = 'D';
	}

	for (int i = 0; i < cnt; i++)
	{
		if (i == cnt - 1) cout << arr[i];
		else cout << arr[i] << '\n';
	}

	return 0;
}