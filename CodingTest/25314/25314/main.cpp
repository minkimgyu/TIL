#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	cin >> cnt;

	for (int i = 0; i < cnt / 4; i++)
	{
		cout << "long ";
	}

	cout << "int";

	return 0;
}