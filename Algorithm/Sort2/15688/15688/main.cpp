#include <iostream>
using namespace std;

const int maxSize = 1000000 + 5;
int mArr[maxSize];
int pArr[maxSize];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		if (item < 0)
		{
			mArr[-item]++;
		}
		else
		{
			pArr[item]++;
		}
	}

	for (int i = maxSize - 1; i > -1; i--)
	{
		if (mArr[i] == 0) continue;

		for (int j = 0; j < mArr[i]; j++) cout << -i << '\n';
	}

	for (int i = 0; i < maxSize; i++)
	{
		if (pArr[i] == 0) continue;

		for (int j = 0; j < pArr[i]; j++) cout << i << '\n';
	}

	return 0;
}