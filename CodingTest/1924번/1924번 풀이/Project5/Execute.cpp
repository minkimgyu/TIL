#include <iostream>
using namespace std;

int main()
{
	int mon, day = 0;

	int tmp[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
				 // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12¿ù
	cin >> mon >> day;

	int totalDay = 0;

	for (int i = 1; i < mon; i++)
	{
		totalDay += tmp[i-1];
	}
	totalDay += day;

	int whatDay = totalDay % 7;

	if (whatDay == 0)
	{
		cout << "SUN";
	}
	else if (whatDay == 1) 
	{
		cout << "MON";
	}
	else if (whatDay == 2)
	{
		cout << "TUE";
	}
	else if (whatDay == 3)
	{
		cout << "WED";
	}
	else if (whatDay == 4)
	{
		cout << "THU";
	}
	else if (whatDay == 5)
	{
		cout << "FRI";
	}
	else if (whatDay == 6)
	{
		cout << "SAT";
	}

	return 0;
}