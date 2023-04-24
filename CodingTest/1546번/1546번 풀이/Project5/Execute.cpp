#include <iostream>
using namespace std;

int main()
{
	int count;
	cin >> count;

	long double tmp[1000];
	long double max = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> tmp[i];

		if (i == 0)
		{
			max = tmp[i];
		}
		else
		{
			if (tmp[i] > max)
			{
				max = tmp[i];
			}
		}
	}

	long double sum = 0;

	for (int i = 0; i < count; i++)
	{
		sum += tmp[i] / max * 100;
	}

	cout << sum / count;

	return 0;
}