#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	bool isNot = false;

	int size = s.size() - 1;
	for (int i = 0; i <= size / 2; i++)
	{
		if (s[i] != s[size - i])
		{
			isNot = true;
			break;
		}
	}

	if (isNot)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	

	return 0;
}