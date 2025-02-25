#include <iostream>
#include <string>
using namespace std;

int state;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (s == "add")
		{
			int num;
			cin >> num;

			state |= (1 << (num - 1));
		}
		else if (s == "remove")
		{
			int num;
			cin >> num;

			state &= (~(1 << (num - 1)));
		}
		else if (s == "check")
		{
			int num;
			cin >> num;

			cout << ((state >> (num - 1)) & 1);
			if (i != n - 1) cout << '\n';
		}
		else if (s == "toggle")
		{
			int num;
			cin >> num;

			state ^= (1 << (num - 1));
		}
		else if (s == "all")
		{
			state = 0xfffff;
		}
		else if (s == "empty")
		{
			state = 0;
		}
	}

	return 0;
}