#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int size1 = 1000;
	const int size2 = 1001;

	string s;
	string t;

	getline(cin, s);
	getline(cin, t);

	while (t.size() >= s.size())
	{
		char item = t.back();
		if (item == 'A')
		{
			t.pop_back();
		}
		else if (item == 'B')
		{
			t.pop_back();

			int size = t.size();
			for (int i = 0; i < size / 2; i++)
			{
				char back = t[size - i - 1];
				t[size - i - 1] = t[i];
				t[i] = back;
			}
		}

		bool isSame = true;
		int size = t.size();
		if (s.size() == size)
		{
			for (int i = 0; i < size; i++)
			{
				if (s[i] != t[i]) isSame = false;
			}

			if (isSame == true)
			{
				cout << 1;
				return 0;
			}
		}
		else if (s.size() > size)
		{
			cout << 0;
			return 0;
		}
	}

	cout << 0;
	return 0;
}