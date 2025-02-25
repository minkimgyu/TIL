#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int result = 0;
	int n = 5;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;

		result += item * item;
	}

	cout << result % 10;

	return 0;
}