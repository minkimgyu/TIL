#include <iostream>
using namespace std;

int main()
{
	int h, m;
	int space;

	cin >> h >> m;
	cin >> space;

	m = m + space;

	if (m >= 60)
	{
		int hTmp = m / 60;
		int mTmp = m % 60;

		h += hTmp;
		m = mTmp;

		if (h >= 24)
		{
			h -= 24;
		}
	}
	
	cout << h << " " << m;

	return 0;
}