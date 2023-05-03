#include <iostream>
using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;

	int tmp = m - 45;

	if (m >= 45)
	{
		m = tmp;
	}
	else
	{
		h -= 1;
		if (h < 0) h = 23;

		m = 60 + tmp;
	}

	cout << h << " " << m;

	return 0;
}