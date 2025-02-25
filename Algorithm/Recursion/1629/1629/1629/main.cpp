#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	// 10, 11, 12
	//
	//
	// 10, 100, 1000, 10000, 100000, 1000000 ...
	// 2, 4, 4, 4, 4 .....


	// 3, 11, 4
	// 
	// 
	// 3, 9, 27, 81, 243, 729, 2187 ...
	// 1, 1, 3, 1, 3, 1, 3 ....

	long long int result = 1;

	for (int i = 0; i < b; i++)
	{
		result *= a;
		result %= c;
	}

	cout << result;
	return 0;
}