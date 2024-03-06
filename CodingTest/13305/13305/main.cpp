#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int* way = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		int tmp;
		cin >> tmp;
		*(way + i) = tmp;
	}

	int* price = new int[n];
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		*(price + i) = tmp;
	}



	return 0;
}