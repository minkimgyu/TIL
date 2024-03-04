#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
	}

	return 0;
}