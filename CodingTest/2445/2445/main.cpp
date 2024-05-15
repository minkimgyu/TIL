#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < (2 * n - 1); i++)
	{
		if (i < n)
		{
			for (int j = 0; j < i + 1; j++)
			{
				cout << "*";
			}

			for (int j = 0; j < (2 * n) - 2 * (i + 1); j++)
			{
				cout << " ";
			}

			for (int j = 0; j < i + 1; j++)
			{
				cout << "*";
			}
		}
		else
		{
			for (int j = (2 * n - 1) - i; j > 0; j--)
			{
				cout << "*";
			}

			for (int j = 0; j < 2 * (i + 1) - (2 * n); j++)
			{
				cout << " ";
			}

			for (int j = (2 * n - 1) - i; j > 0; j--)
			{
				cout << "*";
			}
		}

		if(i != 2 * n - 2) cout << '\n';
	}

	return 0;
}