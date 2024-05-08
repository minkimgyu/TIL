#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int tmp = 1;

	for (int i = 0; i < n; i++)
	{
		for (int z = n - 1 - i; z > 0; z--)
		{
			cout << " ";
		}

		for (int j = 0; j < tmp; j++)
		{
			cout << "*";
		}

		tmp += 2;


		if(i != n - 1) cout << '\n';
	}

	return 0;
}