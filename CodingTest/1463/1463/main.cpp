#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	int cnt = 0;

	while (x != 1)
	{
		cnt++;

		if (x % 3 == 0)
		{
			x /= 3;
			continue;
		}
		else
		{
			x -= 1;
			continue;
		}

		if (x / 2 == 1) x /= 2;
	}

	cout << cnt;

	return 0;
}