#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, m, s, time;

	cin >> h >> m >> s;
	cin >> time;

	s += time;

	int leftSecond = s % 60;
	int addMinute = s / 60;

	s = leftSecond;
	m += addMinute;

	int leftMinute = m % 60;
	int addHour = m / 60;

	m = leftMinute;
	h += addHour;

	h = h % 24;

	cout << h << " " << m << " " << s;

	return 0;
}