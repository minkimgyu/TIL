#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 2 * n; i += 2)
	{
		for (int j = 0; j < i / 2; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < 2 * n - 1 - i; j++)
		{
			cout << "*";
		}

		if(i != 2 * n - 2) cout << "\n";
	}

	return 0;
}