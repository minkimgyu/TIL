#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int h, w, n;
		cin >> h >> w >> n;

		int row = n % h; // 4
		int col = n / h;

		if (row == 0)
		{
			row = h;
		}
		else
		{
			col += 1;
		}

		int sum = row * 100 + col;
		cout << sum << '\n';
	}

	return 0;
}