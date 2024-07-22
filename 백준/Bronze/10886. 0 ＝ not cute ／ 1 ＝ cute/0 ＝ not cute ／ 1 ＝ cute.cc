#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int index;
		cin >> index;

		sum += index;
	}

	if (sum > (float)n / 2)
	{
		cout << "Junhee is cute!";
	}
	else
	{
		cout << "Junhee is not cute!";
	}

	return 0;
}