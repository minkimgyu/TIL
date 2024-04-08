#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 1 3 5 7 9

	// 2n - 1
	int size = 2 * n - 1;

	int index = 1;

	for (int i = 1; i <= size; i++)
	{
		int mid = (int)(size / 2) + 1;

		if (i <= mid)
		{
			for (int j = 0; j < mid - i; j++)
			{
				cout << " ";
			}

			for (int j = 0; j < 2 * i - 1; j++) // 1 3 5 7 9 -- 1 2 3 4 5 4 3 2 1
			{
				cout << "*";
			}
		}
		else
		{
			for (int j = 0; j < i - mid; j++)
			{
				cout << " ";
			}

			for (int j = size * 2 - 1; j >= 2 * i - 1; j--) // size * 2 - 1¿Ã ≥°¿”
			{
				cout << "*";
			}
		}

		cout << '\n';
	}

	return 0;
}
